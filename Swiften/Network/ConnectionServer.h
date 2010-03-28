#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/signal.hpp>

#include "Swiften/Network/Connection.h"

namespace Swift {
	class ConnectionServer {
		public:
			virtual ~ConnectionServer();

			boost::signal<void (boost::shared_ptr<Connection>)> onNewConnection;
	};
}
