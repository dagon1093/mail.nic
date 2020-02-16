#include <time.h>
	
	
	
int day_seconds(int x) {
	time_t t;
	int seconds;
	int sec_today;
	
	t = time(NULL); //записываем время в секундах с 1970 года
	seconds = 24*60*60; // находим количество секунд в сутках
	sec_today = t%seconds +10800; //остаток от деления + 3 часа в секундах будет количество секунд в нашем часовом поясе с начала дня
	sec_today = sec_today + x;
	return sec_today;
}
	
	
Action()
{
	int x;
	x = atoi(lr_eval_string("{Y}")); // рандомное число из параметра записываю в переменную х
	
	x = day_seconds(x);
	
	lr_save_int(x,"rand_num");
	
	lr_start_transaction("0_homepage");

	web_set_sockets_option("SSL_VERSION", "TLS");

/*	На этот момент я еще не знал как бороться с кодировкой, в будущих скриптах включал галочку на поддержку UTF. 
	Но так же, в некоторых скриптах регулярка не может распарсить в кодировке UTF. Решалось отключением коодировки.*/
	
	web_reg_find("Search=All", "Text=Р­Р»РµРєС‚СЂРѕРЅРЅР°СЏ РїРѕС‡С‚Р° РѕС‚ RU-CENTER", LAST);

	web_url("www.mail.nic.ru", 
		"URL=https://www.mail.nic.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("0_homepage", LR_AUTO);

	
	
	
	
	lr_start_transaction("1_login");

	web_custom_request("json_auth.php", 
		"URL=https://mail.nic.ru/proxy/json_auth.php", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.mail.nic.ru/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("json_auth.php_2", 
		"URL=https://mail.nic.ru/proxy/json_auth.php", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.mail.nic.ru/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"username\":\"{My_email}\",\"password\":\"{password}\",\"host\":\"https://mail.nic.ru\"}", 
		LAST);


/*Correlation comment: Automatic rules - Do not change!  
Original value='bb63484f71116a8a998676db194f2039' 
Name ='_token' 
Type ='Rule' 
AppName ='mail.nic' 
RuleName ='Rule_7'*/
	web_reg_save_param_regexp(
		"ParamName=_token",
		"RegExp=\"request_token\":\"(.*?)\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/roundcubemail/*",
		LAST);



	web_reg_find("Search=All","Text=Copyright",LAST);
	web_reg_find("Search=All","Text={My_email}",LAST);


	web_url("roundcubemail", 
		"URL=https://mail.nic.ru/roundcubemail/?_task=mail", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.mail.nic.ru/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("watermark.html", 
		"URL=https://mail.nic.ru/roundcubemail/skins/outlook/watermark.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_login",LR_AUTO);

	
	
	
	
	lr_start_transaction("2_message");

/*Correlation comment: Automatic rules - Do not change!  
Original value='Sent' 
Name ='_store_target' 
Type ='Rule' 
AppName ='mail.nic' 
RuleName ='rule'*/
	web_reg_save_param_regexp(
		"ParamName=_store_target",
		"RegExp=option\\ value=\"(.*?)\"\\ selected",
		"Ordinal=4",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/roundcubemail/*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='3693747465dc3227acb0dc' 
Name ='_id' 
Type ='Rule' 
AppName ='mail.nic' 
RuleName ='compose_id'*/
	web_reg_save_param_regexp(
		"ParamName=_id",
		"RegExp=compose&_id=(.*?)\\\r\\\n",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Headers",
		"RequestUrl=*/roundcubemail/*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='5761600' 
Name ='_from' 
Type ='Rule' 
AppName ='mail.nic' 
RuleName ='rule'*/
	web_reg_save_param_regexp(
		"ParamName=_from",
		"RegExp=option\\ value=\"(.*?)\"\\ selected",
		"Ordinal=1",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/roundcubemail/*",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='html' 
Name ='CorrelationParameter' 
Type ='Rule' 
AppName ='mail.nic' 
RuleName ='rule'*/
	web_reg_save_param_regexp(
		"ParamName=CorrelationParameter",
		"RegExp=option\\ value=\"(.*?)\"\\ selected",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/roundcubemail/*",
		LAST);
// Так же из-за кодировки отказывается искать кирилицу на странице.
//	web_reg_find("Search=All","Text=Добавить вложение",	LAST);
//	web_reg_find("Search=All","Text=Отправить",	LAST);

	web_reg_find("Search=Body",	"Text=Followup-To",	LAST);

	web_url("roundcubemail_2", 
		"URL=https://mail.nic.ru/roundcubemail/?_task=mail&_mbox=INBOX&_action=compose", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_mbox=INBOX", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("2_message",LR_AUTO);

	
	
	
	lr_start_transaction("3_sent");

	lr_save_timestamp("CurrentTimeStamp", LAST);
	
	web_reg_find("Search=All","Text=Sent", LAST);

	web_submit_data("roundcubemail_5",
		"Action=https://mail.nic.ru/roundcubemail/?_task=mail&_unlock=loading{CurrentTimeStamp}&_lang=ru_RU&_framed=1",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id={_id}",
		"Snapshot=t9.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=_token", "Value={_token}", ENDITEM,
		"Name=_task", "Value=mail", ENDITEM,
		"Name=_action", "Value=send", ENDITEM,
		"Name=_id", "Value={_id}", ENDITEM,
		"Name=_attachments", "Value=", ENDITEM,
		"Name=_from", "Value={_from}", ENDITEM,
		"Name=_to", "Value={adr_email}", ENDITEM,
		"Name=_cc", "Value=", ENDITEM,
		"Name=_bcc", "Value=", ENDITEM,
		"Name=_replyto", "Value=", ENDITEM,
		"Name=_followupto", "Value=", ENDITEM,
		"Name=_subject", "Value={title}", ENDITEM,
		"Name=editorSelector", "Value={CorrelationParameter}", ENDITEM,
		"Name=_priority", "Value=0", ENDITEM,
		"Name=_store_target", "Value={_store_target}", ENDITEM,
		"Name=_draft_saveid", "Value=", ENDITEM,
		"Name=_draft", "Value=", ENDITEM,
		"Name=_is_{CorrelationParameter}", "Value=1", ENDITEM,
		"Name=_framed", "Value=1", ENDITEM,
		"Name=_message", "Value=<p>{Message}</p>\r\n"
		"<div id=\"_rc_sig\">-- <br />\r\n"
		"<p>{signature} {rand_num}</p>\r\n"
		"</div>", ENDITEM,
		LAST);


	web_reg_find("Search=All",
		"Text=Copyright (C) 2005-2014 The Roundcube Dev Team",
		LAST);

	web_url("roundcubemail_6",
		"URL=https://mail.nic.ru/roundcubemail/?_task=mail&_refresh=1&_mbox=INBOX",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id={_id}",
		"Snapshot=t10.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("3_sent",LR_AUTO);

	
	
	
	lr_start_transaction("4_logout");

	web_reg_find("Search=All",
		"Text=RU-CENTER",
		LAST);

	web_url("roundcubemail_7",
		"URL=https://mail.nic.ru/roundcubemail/?_task=logout&_token={_token}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t11.inf",
		"Mode=HTML",
		LAST);

	web_url("www.mail.nic.ru_2", 
		"URL=https://www.mail.nic.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=https://mail.nic.ru/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("4_logout",LR_AUTO);

	return 0;
}