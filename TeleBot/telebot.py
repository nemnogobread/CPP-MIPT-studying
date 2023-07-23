import telebot

bot = telebot.Telebot('6556691353:AAG54E4sdBBD79j3pX2x_WDSfrKspp5hepM')

@bot.message_handlers(commands=['/start'])
