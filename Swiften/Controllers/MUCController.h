#ifndef SWIFTEN_MUCController_H
#define SWIFTEN_MUCController_H

#include <boost/shared_ptr.hpp>

#include "Swiften/Base/String.h"
#include "Swiften/Controllers/ChatControllerBase.h"
#include "Swiften/Elements/Message.h"
#include "Swiften/Elements/DiscoInfo.h"
#include "Swiften/JID/JID.h"
#include "Swiften/MUC/MUC.h"
#include "Swiften/MUC/MUCOccupant.h"

namespace Swift {
	class StanzaChannel;
	class IQRouter;
	class ChatWindow;
	class ChatWindowFactory;
	class Roster;
	class TreeWidgetFactory;

	class MUCController : public ChatControllerBase {
		public:
			MUCController(const JID &muc, const String &nick, StanzaChannel* stanzaChannel, IQRouter* iqRouter, ChatWindowFactory* chatWindowFactory, TreeWidgetFactory *treeWidgetFactory, PresenceOracle* presenceOracle);
			~MUCController();
		
		protected:
			void preSendMessageRequest(boost::shared_ptr<Message> message);
			bool isIncomingMessageFromMe(boost::shared_ptr<Message> message);
			String senderDisplayNameFromMessage(JID from);
		private:
			void handleWindowClosed();
			void handleOccupantJoined(const MUCOccupant& occupant);
			void handleOccupantLeft(const MUCOccupant& occupant, MUC::LeavingType type, const String& reason);
			void handleOccupantPresenceChange(boost::shared_ptr<Presence> presence);
			MUC *muc_;
			String nick_;
			TreeWidgetFactory *treeWidgetFactory_;
			Roster *roster_;
	};
}
#endif

