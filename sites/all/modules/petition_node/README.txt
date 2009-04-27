/* $Id: README.txt,v 1.1 2009/03/17 22:09:15 gauvain Exp $ */

Petition module the creation of petition nodes to collect signatures to a cause.
The signers have to confirm their signatures by clicking to a link included in an email they automatically received upon signing the petition.
The Signatures can be exported as a .csv file.
If you have the ip2cc module installed, benefit from extended functionalities such as restricting the petition to a geographic area, say you want to create a petition that only should concern citizens living in a given country.

Themer
-------
You can create a node-petition.tpl.php file to your theme directory.
The default $content variable contains both the Petition body and the petition form.
However, you may wish distinguish between the body and the from.

If so, please:
1/ remove the $content variable from the node-petition.tpl.php file.
2/ replace it with the 2 following variables : $petition_body and $petition_form


Installation
------------

Copy petition module to your module directory and then enable on the admin
modules page.  You can change the general petition settings on admin/settings/petition.

Author
------
Gauvain
gauvain@kth.se