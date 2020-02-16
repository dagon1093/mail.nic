Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("www.mail.nic.ru", 
		"URL=https://www.mail.nic.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://storage.nic.ru/ru/images/jpg/shut4.jpg", ENDITEM, 
		LAST);

	lr_start_transaction("1_login");

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://www.mail.nic.ru");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	lr_think_time(19);

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

	lr_think_time(28);

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
		"Body={\"username\":\"a.yakovlev@q-expert.com\",\"password\":\"4oiG3Iuy\",\"host\":\"https://mail.nic.ru\"}", 
		LAST);

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("roundcubemail", 
		"URL=https://mail.nic.ru/roundcubemail/?_task=mail", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.mail.nic.ru/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=skins/larry/images/buttons.png?v=51d4.15699", "Referer=https://mail.nic.ru/roundcubemail/skins/larry/styles.min.css?s=1493368165", ENDITEM, 
		"Url=skins/outlook/skin/images/quota.png", "Referer=https://mail.nic.ru/roundcubemail/skins/outlook/common/desktop.css?s=1461156894", ENDITEM, 
		"Url=skins/larry/images/splitter.png?v=2724.136", "Referer=https://mail.nic.ru/roundcubemail/skins/larry/styles.min.css?s=1493368165", ENDITEM, 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"nested-navigate");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("watermark.html", 
		"URL=https://mail.nic.ru/roundcubemail/skins/outlook/watermark.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=skin/images/loader.gif", "Referer=https://mail.nic.ru/roundcubemail/skins/outlook/common/st_buttons_desktop.css?s=1461156894", ENDITEM, 
		"Url=common/icons_fa/fontawesome-webfont.woff?v=4.1.0", "Referer=https://mail.nic.ru/roundcubemail/skins/outlook/common/ic_fa_desktop.css?s=1461156894", ENDITEM, 
		"Url=skin/fonts/JLrcxvhkM17op1c4raL9Fg.woff", "Referer=https://mail.nic.ru/roundcubemail/skins/outlook/skin/skin_desktop.css?s=1461156894", ENDITEM, 
		"Url=/roundcubemail/program/resources/blank.tif", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_mbox=INBOX", ENDITEM, 
		"Url=/roundcubemail/?_task=mail&_refresh=1&_mbox=INBOX&_remote=1&_unlock=loading1573069416276&_action=list&_=1573069415732", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail", ENDITEM, 
		"Url=/roundcubemail/?_task=mail&_remote=1&_unlock=0&_action=getunread&_=1573069415733", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_mbox=INBOX", ENDITEM, 
		"Url=common/watermark.jpg?v=e784.5000", ENDITEM, 
		LAST);

	lr_end_transaction("1_login",LR_AUTO);

	lr_start_transaction("2_message");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("roundcubemail_2", 
		"URL=https://mail.nic.ru/roundcubemail/?_task=mail&_mbox=INBOX&_action=compose", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_mbox=INBOX", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=skins/larry/images/googiespell/change_lang.gif", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/langs/ru.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/themes/modern/theme.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/autolink/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/charmap/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/code/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/colorpicker/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/directionality/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/emoticons/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/link/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/image/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/media/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/nonbreaking/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/paste/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/table/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/tabfocus/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/searchreplace/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/textcolor/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/plugins/spellchecker/plugin.min.js?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=skins/larry/images/filedrop.png?v=ba79.421", "Referer=https://mail.nic.ru/roundcubemail/skins/larry/mail.min.css?s=1493368165", ENDITEM, 
		"Url=program/js/tinymce/skins/lightgray/skin.min.css?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/skins/lightgray/content.min.css?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/roundcube/content.css?s=4010900", "Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", ENDITEM, 
		"Url=program/js/tinymce/skins/lightgray/fonts/tinymce-small.woff", "Referer=https://mail.nic.ru/roundcubemail/program/js/tinymce/skins/lightgray/skin.min.css?s=4010900", ENDITEM, 
		LAST);

	lr_end_transaction("2_message",LR_AUTO);

	lr_start_transaction("3_sent");

	web_add_auto_header("Origin", 
		"https://mail.nic.ru");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_auto_header("X-Roundcube-Request", 
		"bb63484f71116a8a998676db194f2039");

	lr_think_time(16);

	web_submit_data("roundcubemail_3", 
		"Action=https://mail.nic.ru/roundcubemail/?_task=mail&_action=autocomplete", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_search", "Value=da", ENDITEM, 
		"Name=_source", "Value=", ENDITEM, 
		"Name=_reqid", "Value=1573069455056", ENDITEM, 
		"Name=_remote", "Value=1", ENDITEM, 
		"Name=_unlock", "Value=0", ENDITEM, 
		LAST);

	lr_think_time(42);

	web_submit_data("roundcubemail_4", 
		"Action=https://mail.nic.ru/roundcubemail/?_task=mail&_action=refresh", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_last", "Value=1573069437", ENDITEM, 
		"Name=_remote", "Value=1", ENDITEM, 
		"Name=_unlock", "Value=loading1573069497958", ENDITEM, 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_revert_auto_header("X-Roundcube-Request");

	web_add_auto_header("Sec-Fetch-Mode", 
		"nested-navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(4);

	web_submit_data("roundcubemail_5", 
		"Action=https://mail.nic.ru/roundcubemail/?_task=mail&_unlock=loading1573069502049&_lang=ru_RU&_framed=1", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=_token", "Value=bb63484f71116a8a998676db194f2039", ENDITEM, 
		"Name=_task", "Value=mail", ENDITEM, 
		"Name=_action", "Value=send", ENDITEM, 
		"Name=_id", "Value=3693747465dc3227acb0dc", ENDITEM, 
		"Name=_attachments", "Value=", ENDITEM, 
		"Name=_from", "Value=5761600", ENDITEM, 
		"Name=_to", "Value=dagon1093@gmail.com", ENDITEM, 
		"Name=_cc", "Value=", ENDITEM, 
		"Name=_bcc", "Value=", ENDITEM, 
		"Name=_replyto", "Value=", ENDITEM, 
		"Name=_followupto", "Value=", ENDITEM, 
		"Name=_subject", "Value=teeeeeeeeeeeest", ENDITEM, 
		"Name=editorSelector", "Value=html", ENDITEM, 
		"Name=_priority", "Value=0", ENDITEM, 
		"Name=_store_target", "Value=Sent", ENDITEM, 
		"Name=_draft_saveid", "Value=", ENDITEM, 
		"Name=_draft", "Value=", ENDITEM, 
		"Name=_is_html", "Value=1", ENDITEM, 
		"Name=_framed", "Value=1", ENDITEM, 
		"Name=_message", "Value=<p>teeeeeeeeeeeest</p>\r\n<div id=\"_rc_sig\">-- <br />\r\n<p><span>&lt;p style=\"margin: 0cm; margin-bottom: 0.0001pt; font-size: 11pt; font-family: Calibri,sans-serif;\"&gt;&lt;span&gt;С уважением,&lt;/span&gt;&lt;/p&gt;</span><br /><span>&lt;p style=\"margin: 0cm; margin-bottom: 0.0001pt; font-size: 11pt; font-family: Calibri,sans-serif;\"&gt;&lt;span&gt;Яковлев Александр&lt;/span&gt;&lt;/p&gt;</span><br /><span>&lt;p style=\"margin: 0cm; "
		"margin-bottom: 0.0001pt; font-size: 11pt; font-family: Calibri,sans-serif;\"&gt;&lt;strong&gt;&lt;em&gt;&lt;span style=\"font-size: 12pt; color: #538135;\"&gt;Quality Expert&lt;/span&gt;&lt;/em&gt;&lt;/strong&gt;&lt;/p&gt;</span><br /><span>&lt;p style=\"margin: 0cm; margin-bottom: 0.0001pt; font-size: 11pt; font-family: Calibri,sans-serif;\"&gt;&lt;span&gt;&nbsp;<span>�\x98нженер по нагрузочному тестированию</span>&lt;/span&gt;&lt;/p&gt;</span><br /><span>&lt;p "
		"style=\"margin: 0cm; margin-bottom: 0.0001pt; font-size: 11pt; font-family: Calibri,sans-serif;\"&gt;&lt;em&gt;&lt;span&gt;&lt;span class=\"wmi-callto\"&gt;+7 (951) 758-51-90&lt;/span&gt;&lt;/span&gt;&lt;/em&gt;&lt;/p&gt;</span></p>\r\n</div>", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_url("roundcubemail_6", 
		"URL=https://mail.nic.ru/roundcubemail/?_task=mail&_refresh=1&_mbox=INBOX", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://mail.nic.ru/roundcubemail/?_task=mail&_action=compose&_id=3693747465dc3227acb0dc", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_sent",LR_AUTO);

	lr_start_transaction("4_logout");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("roundcubemail_7", 
		"URL=https://mail.nic.ru/roundcubemail/?_task=logout&_token=bb63484f71116a8a998676db194f2039", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	web_url("www.mail.nic.ru_2", 
		"URL=https://www.mail.nic.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=https://mail.nic.ru/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://storage.nic.ru/ru/images/jpg/shutte1.jpg", ENDITEM, 
		LAST);

	lr_end_transaction("4_logout",LR_AUTO);

	return 0;
}