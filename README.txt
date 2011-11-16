README.txt
==========

Brain Forum is an entity-based disucssion forum module for Drupal 7 with
Views-integration. It also supports BBCode (http://drupal.org/project/bbcode).


INSTALLATION
==============

Just enable the module as usual.


USAGE
==============

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


BBCODE SUPPORT
==============

To use BBCode with Brain Forum:
- Download and enable BBCode (http://drupal.org/project/bbcode)

If BBCode is enabled when installing Brain Forum, a new text format is automatically created and you don't have to do anything.

If you installed BBCode after installing Brain Forum:
- Create a new text format (admin/config/content/formats/add)
    and give the name "BBCode" (machine name "bbcode") to it
- Configure the text format to use BBCode filter
- Brain Forum will now default to the BBCode filter if the current user has
    permission to use it
