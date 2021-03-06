/*
 * Copyright (c) 2013-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma clang diagnostic ignored "-Wunused-private-field"

#include <Swiften/Serializer/PayloadSerializers/PubSubOwnerSubscriptionsSerializer.h>
#include <Swiften/Serializer/XML/XMLElement.h>
#include <memory>

#include <Swiften/Serializer/PayloadSerializerCollection.h>
#include <Swiften/Base/foreach.h>
#include <Swiften/Serializer/PayloadSerializers/PubSubOwnerSubscriptionSerializer.h>
#include <Swiften/Serializer/XML/XMLRawTextNode.h>

using namespace Swift;

PubSubOwnerSubscriptionsSerializer::PubSubOwnerSubscriptionsSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubOwnerSubscriptionsSerializer::~PubSubOwnerSubscriptionsSerializer() {
}

std::string PubSubOwnerSubscriptionsSerializer::serializePayload(std::shared_ptr<PubSubOwnerSubscriptions> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("subscriptions", "http://jabber.org/protocol/pubsub#owner");
    element.setAttribute("node", payload->getNode());
    foreach(std::shared_ptr<PubSubOwnerSubscription> item, payload->getSubscriptions()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubOwnerSubscriptionSerializer(serializers).serialize(item)));
    }
    return element.serialize();
}


