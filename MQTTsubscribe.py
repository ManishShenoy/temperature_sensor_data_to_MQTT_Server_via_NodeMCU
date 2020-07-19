import paho.mqtt.subscribe as subscribe
while True:
      msg = subscribe.simple("Temperature", hostname="")
      print("%s %s" % (msg.topic, msg.payload))
