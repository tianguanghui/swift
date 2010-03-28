#pragma once

#include "Swiften/Queries/Responder.h"

namespace Swift {
	template<typename T>
	class SetResponder : public Responder<T> {
		public:
			SetResponder(IQRouter* router) : Responder<T>(router) {}

		private:
			virtual bool handleGetRequest(const JID&, const String&, boost::shared_ptr<T>) { return false; }
	};
}
