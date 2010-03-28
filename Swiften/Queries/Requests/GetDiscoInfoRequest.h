#pragma once

#include "Swiften/Queries/GenericRequest.h"
#include "Swiften/Elements/DiscoInfo.h"

namespace Swift {
	class GetDiscoInfoRequest : public GenericRequest<DiscoInfo> {
		public:
			GetDiscoInfoRequest(const JID& jid, IQRouter* router) :
					GenericRequest<DiscoInfo>(IQ::Get, jid, boost::shared_ptr<DiscoInfo>(new DiscoInfo()), router) {
			}
	};
}
