This code is sponsored by Gloscon Solutions.
Gloscon is an innovative web-design and development company bringing you products that are closer to your web development needs. So if you want the flexibility or modularity of Drupal  to create a e-commerce, community or corporate site or a framework for developing database backed web application in Ruby on Rails , we have it all.

With an array of products, from web designing to SEO,
we make sure that all your web related needs are satisfied. With a satisfied clients list ranging from the Fortune 500 companies to start-ups, we know exactly what our customers want.

In order to install it on your site, download the following and create a new database.
	Import the attached database nnyd.sql to your new database.
	Assign the '$db_url' parameter of file settings.php the value of your newly created database.
	This file is located in yourfolder/sites/default/settings.php
	the admin login details are nnydadmin/nnydadmin.

Change the paypal donation settings to:
	Path: http://yoursite.com/admin/settings/lm_paypal/settings
	LM PayPal Business/Premier Email: your paypal account id
	LM PayPal Host: www.paypal.com

Change the newsletter settings to:
	Path: http://yoursite.com/admin/settings/simplenews/newsletter
	Change parameters: Email address, From, nameFrom email address to your desired settings.

Please enter your Google Analytics Account Number on:
	Path: http://yoursite.com/admin/settings/googleanalytics

Enter path of your server where the banners are:
	Path: http://yoursite.com/admin/settings/openads
	Fields: The OpenX delivery url, The OpenX https delivery url
	Also include your zone id and name.

Change the following fields as per your requirements at:
	Path: http://yoursite.com/admin/settings/site-information
	Fields: Name, E-mail address, Slogan, Footer message.

Change the following setting to recieve e-mails when join-nnyd form is filled:
	Path: yourfolder/modules/nnydmod/nnydmod.module
	Change: In function nnydmod_nodeapi() change 
	$message['id'] ='demo';
	$message['to'] ='demo@demo.com'; with the 'id' you wish to identify the mail. and 'to' with the 
	e-mail id where you wish to recieve the notification.
