#ifndef SWIFTEN_ChatController_H
#define SWIFTEN_ChatController_H

#include "Swiften/Controllers/ChatControllerBase.h"

namespace Swift {
	class NickResolver;
	class ChatController : public ChatControllerBase {
		public:
			ChatController(StanzaChannel* stanzaChannel, IQRouter* iqRouter, ChatWindowFactory* chatWindowFactory, const JID &contact, NickResolver* nickResolver, PresenceOracle* presenceOracle);
			~ChatController() {};
			//boost::signal<void (const JID&, const JID&)> onJIDChanged;
		protected:
			bool isIncomingMessageFromMe(boost::shared_ptr<Message> message);
			void postSendMessage(const String &body);
			void preHandleIncomingMessage(boost::shared_ptr<Message> message);
			String senderDisplayNameFromMessage(JID from);
		private:
			NickResolver* nickResolver_;
			JID contact_;
	};
}
#endif

