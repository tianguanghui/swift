/*
 * Copyright (c) 2010 Kevin Smith
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */

#include "Swiften/Roster/XMPPRosterController.h"

#include <boost/bind.hpp>

#include "Swiften/Base/foreach.h"
#include "Swiften/Elements/RosterItemPayload.h"
#include "Swiften/Queries/IQRouter.h"
#include "Swiften/Queries/Requests/GetRosterRequest.h"
#include "Swiften/EventLoop/MainEventLoop.h"
#include "Swiften/Roster/Roster.h"
#include "Swiften/Roster/SetPresence.h"
#include "Swiften/Roster/OfflineRosterFilter.h"
#include "Swiften/Roster/XMPPRoster.h"

namespace Swift {
	
/**
 * The controller does not gain ownership of these parameters.
 */
XMPPRosterController::XMPPRosterController(IQRouter* iqRouter, XMPPRoster* xmppRoster) : iqRouter_(iqRouter), rosterPushResponder_(iqRouter), xmppRoster_(xmppRoster) {
	rosterPushResponder_.onRosterReceived.connect(boost::bind(&XMPPRosterController::handleRosterReceived, this, _1));
}

void XMPPRosterController::requestRoster() {
	xmppRoster_->clear();
	GetRosterRequest::ref rosterRequest = GetRosterRequest::create(iqRouter_);
	rosterRequest->onResponse.connect(boost::bind(&XMPPRosterController::handleRosterReceived, this, _1));
	rosterRequest->send();
}

void XMPPRosterController::handleRosterReceived(boost::shared_ptr<RosterPayload> rosterPayload) {
	foreach(const RosterItemPayload& item, rosterPayload->getItems()) {
		//Don't worry about the updated case, the XMPPRoster sorts that out.
		if (item.getSubscription() == RosterItemPayload::Remove) {
			xmppRoster_->removeContact(item.getJID());
		} else {
			xmppRoster_->addContact(item.getJID(), item.getName(), item.getGroups(), item.getSubscription());
		}
	}
}

}