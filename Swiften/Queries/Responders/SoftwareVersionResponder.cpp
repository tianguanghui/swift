#include "Swiften/Queries/Responders/SoftwareVersionResponder.h"
#include "Swiften/Queries/IQRouter.h"

namespace Swift {

SoftwareVersionResponder::SoftwareVersionResponder(
		const String& client, const String& version, IQRouter* router) : 
			Responder<SoftwareVersion>(router),  client_(client), version_(version) {
}

bool SoftwareVersionResponder::handleGetRequest(const JID& from, const String& id, boost::shared_ptr<SoftwareVersion>) {
	sendResponse(from, id, boost::shared_ptr<SoftwareVersion>(new SoftwareVersion(client_, version_)));
	return true;
}

bool SoftwareVersionResponder::handleSetRequest(const JID&, const String&, boost::shared_ptr<SoftwareVersion>) {
	return false;
}

}
