$Id: README.txt,v 1.3.2.4 2008/12/14 19:02:54 kiam Exp $
XML Sitemap Module
Author: Matthew Loar <matthew at loar dot name>
This module was originally written as part of Google Summer of Code 2005.

DESCRIPTION
-----------
The XML Sitemap module creates an XML site map at
http://www.example.com/?q=sitemap.xml that conforms to the sitemaps.org
specification. It provides many options for customizing the data reported in the
site map.

INSTALLATION
------------
See INSTALL.txt in this directory.

KNOWN ISSUES
------------
Users who have not enabled clean URLs have reported receiving an
"Unsupported file format" error from Google. The solution is to replace
"?q=sitemap.xml" at the end of the submission URL with
"index.php?q=sitemap.xml", or to enable the clean URLs.
Submission URLs for each search engine can be
configured at http://www.example.com/?q=admin/settings/xmlsitemap/engines.

MORE INFORMATION
----------------
The Sitemap protocol: http://sitemaps.org.

Search engines:
http://www.google.com/webmasters/sitemap (Google)
http://developer.yahoo.com/search/siteexplorer/V1/ping.html (Yahoo!)
http://webmaster.live.com/ (Windows Live)

