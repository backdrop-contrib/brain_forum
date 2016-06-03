Brain Forum
==========

Brain Forum is an entity-based disucssion forum module for Backdrop with
Views-integration.

This project is at this time very basic, and is ported for experimental purposes
mostly. Use at your own discretion.

HOW TO INSTALL:
---------------
- Install this module using the official Backdrop CMS instructions at 
https://backdropcms.org/guide/modules



USAGE
---------------

After enabling the module:
- Go to admin/people/permissions to adjust the user permissions.
- Go to admin/structure/taxonomy/forum_categories to add terms for the
discussion categories.

- To create a new thread, go to forum/thread/add
- To view a list of threads, go to forum/
- To view an individual thread, go to forum/thread/<thread_id>
- To edit the output of data, go to
  - admin/structure/views/forum_listing
  - admin/structure/views/forum_thread
- Two templates are provided in the `/templates` folder which can be used to 
theme the thread view and individual responses (views rows) individually.

BBCODE SUPPORT (not yet possible)
---------------

To use BBCode with Brain Forum:
- Download and enable BBCode (http://backdrop.org/project/bbcode)

If BBCode is enabled when installing Brain Forum, a new text format is automatically created and you don't have to do anything.

If you installed BBCode after installing Brain Forum:
- Create a new text format (admin/config/content/formats/add)
    and give the name "BBCode" (machine name "bbcode") to it
- Configure the text format to use BBCode filter
- Brain Forum will now default to the BBCode filter if the current user has
    permission to use it

LICENSE
---------------    

This project is GPL v2 software. See the LICENSE.txt file in this directory 
for complete text.

CURRENT MAINTAINERS
---------------    

Looking for maintainers

CREDITS   
--------------- 

This module is a fork of the Drupal version maintained on Drupal by Ufku 
(https://www.drupal.org/u/ufku)
