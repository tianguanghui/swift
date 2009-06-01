#include <iostream>
#include <boost/bind.hpp>

#include "Swiften/Base/String.h"
#include "Swiften/Base/ByteArray.h"
#include "Swiften/Notifier/GrowlNotifier.h"
#include <QApplication>

using namespace Swift;

void notificationClicked(const String& message) {
	std::cout << "Notification clicked: " << message << std::endl;
}

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	GrowlNotifier notifier("Swift-NotifierTest");
	notifier.showMessage(Notifier::ContactAvailable, "Contact is available", "The contact has become available", ByteArray(), boost::bind(&notificationClicked, "Message 1"));
	return app.exec();
}
