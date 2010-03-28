#pragma once

#include "Swiften/Queries/GenericRequest.h"
#include "Swiften/Elements/RosterPayload.h"

namespace Swift {
	class GetRosterRequest : public GenericRequest<RosterPayload> {
		public:
			GetRosterRequest(IQRouter* router) :
					GenericRequest<RosterPayload>(IQ::Get, JID(), boost::shared_ptr<Payload>(new RosterPayload()), router) {
			}
	};
}
