OVERVIEW
This module helps with integration the openads adserver (http://www.openads.org/) into Drupal. Escpecially it helps with seperating
code (where to place ads in templates) and content (which ads to serve). This module will generate all the JavaScript required to
invoke openads adserver.

UPDATES
2007/2/28 - Initial release

DEPENDENCIES
This module works in Drupal 5.  It requires no other modules.

INSTALLATION
(1) Place the openads folder in your modules direcotry.  This folder should contain openads.module, 
openads.info, and mmm.js
(2) In your site, navigate to Administer/Site Building/Modules, and enable the openads module. It is located in the "Advertising" section.

CONFIGURATION
Go to Administration/Site Configuration/Openads Adserver to set configuration options. Configuration options are split into three parts:
(a) Adserver Settings
     Every Openads Server can be configured differently regarding domains and script names. Therefore, you need to provide in the urls and
     script names to be called. You can copy and paste the values from the adserver's site Settings/Main Settings in the administrator panel.
     If you don't have administrator access on the adserver, ask your administrator for the according values.
(b) Publisher Settings
     Every website is known as a publisher in the openads adserver. Copy the publishers mnemonic and the number of zones for this site here.
(c) Zones
     Now you are ready to enter your zones. Every zone has a unique number and an internal code, you can copy this information from your 
     adserver generated invocation code. Navigate to Inventory/Publishers & Zones/[My site]/Invocation Code. For every zone you'll find
     code like this one:
       <script language='JavaScript' type='text/javascript'>
       <!--
	   az_adjs(52,'siteea111cd');
       //-->
       </script>
     52 is the zone ID and "siteea111cd" is the zone code in question.
     Aditionally you may give your zone a name, to access this zone within template code. You may also for every user role determine, if ads
     are shown or not.

BLOCKS
This module offers as many blocks as zones are defined. The blocks are named after the zones that is "Openads Zone 0", "Openads Zone 1" etc. 
You may enable or disable blocks under Adminstration/Site Building/Blocks.

MANUAL INVOCATION
If you want to place ads within your templates manually, you may use the following code:

<?php print openads_invoke([index]); ?>

Where [index] is the number of one of your zones, that is 0, 1, etc. You may also invoke a zone by its name, like this:

<?php print openads_invoke("leaderboard top"); ?>

The module will take care to generate the according JavaScript after validate if to show ads to the user logged in
	
SPONSORS
This module was sponsored by Ambiweb GmbH, http://www.ambiweb.de
	
CONTRIBUTORS
Gerd Riesselmann (openads@gerd-riesselmann.net) - this module
