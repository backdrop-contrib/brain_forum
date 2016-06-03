<?php

/**
 * @file
 * Provides information about brain_forum entities to views.
 */

/**
 * Implements hook_views_data_alter().
 */
function brain_forum_views_data_alter(&$data) {
  // Add forum_post published or admin field
  $data['brain_forum_forum_post']['status_extra'] = array(
    'title' => t('Published or admin'),
    'help' => t('Filters out unpublished forum_posts if the current user cannot view them.'),
    'filter' => array(
      'field' => 'status',
      'handler' => 'brain_forum_forum_post_handler_filter_status',
      'label' => t('Published or admin'),
    ),
  );

  // Add forum_post.thread_status published or admin field
  $data['brain_forum_forum_post']['thread_status_extra'] = array(
    'title' => t('Thread is published or admin'),
    'help' => t('Filters out forum_posts in unpublished threads if the current user cannot view them.'),
    'filter' => array(
      'field' => 'thread_status',
      'handler' => 'brain_forum_forum_post_handler_filter_thread_status',
      'label' => t('Thread is published or admin'),
    ),
  );


  // Add reply link field
  $data['brain_forum_forum_post']['reply'] = array(
    'field' => array(
      'title' => t('Reply link'),
      'help' => t('Provide a reply link to the forum_post.'),
      'handler' => 'brain_forum_forum_post_handler_reply_field',
    ),
  );

  // Add quote link field
  $data['brain_forum_forum_post']['quote'] = array(
    'field' => array(
      'title' => t('Quote link'),
      'help' => t('Provide a quote link to the forum_post.'),
      'handler' => 'brain_forum_forum_post_handler_quote_field',
    ),
  );

  // Add edit link field
  $data['brain_forum_forum_post']['edit'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a edit link to the forum_post.'),
      'handler' => 'brain_forum_forum_post_handler_edit_field',
    ),
  );
  // Add thread published or admin field
  $data['brain_forum_thread']['status_extra'] = array(
    'title' => t('Published or admin'),
    'help' => t('Filters out unpublished threads if the current user cannot view them.'),
    'filter' => array(
      'field' => 'status',
      'handler' => 'brain_forum_thread_handler_filter_status',
      'label' => t('Published or admin'),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 */
function brain_forum_views_data() {
  $data['brain_forum_forum_post']['table']['group'] = t('Forum post');
  $data['brain_forum_forum_post']['table']['base'] = array(
    'field' => 'pid', // This is the identifier field for the view.
    'title' => t('Forum post'),
    'help' => t('Forum post.'),
    'weight' => -10,
  );
  $data['brain_forum_forum_post']['table']['entity type'] = 'forum_post';

  // Alter the forum_post pid handler
  $data['brain_forum_forum_post']['pid'] = array(
    'title' => t('Post ID'),
    'help' => t('Post ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Alter the forum_post tid handler
  $data['brain_forum_forum_post']['tid'] = array(
    'title' => t('Thread ID'),
    'help' => t('Thread ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array (
      'base' => 'brain_forum_thread',
      'field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Thread tid'),
    )
  );

  // Alter the forum_post is_first handler
  $data['brain_forum_forum_post']['is_first'] = array(
    'title' => t('Post is first'),
    'help' => t('Whether or not the forum_post is first post.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Alter the forum_post title handler
  $data['brain_forum_forum_post']['title'] = array(
    'title' => t('Title'),
    'help' => t('Post title.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Alter the forum_post uid handler
  $data['brain_forum_forum_post']['uid'] = array(
    'title' => t('Author UID'),
    'help' => t('User ID.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_sort_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'relationship' => array(
      'title' => t('Author'),
      'help' => t("The User ID of the post's author."),
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('author'),
    ),
  );

  $data['brain_forum_forum_post']['name'] = array(
    'title' => t('Name'),
    'help' => t('The forum_post author name.'),
    'field' => array(
      'handler' => 'views_handler_field_user_name',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['brain_forum_forum_post']['ip'] = array(
    'title' => t('Author IP'),
    'help' => t('The forum_post author IP address.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['brain_forum_forum_post']['created'] = array(
    'title' => t('Post date'),
    'help' => t('Date and time of when the post was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['brain_forum_forum_post']['changed'] = array(
    'title' => t('Post modified date'),
    'help' => t('Date and time of when the post was modified.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Alter the forum_post status handler
  $data['brain_forum_forum_post']['status'] = array(
    'title' => t('Published'),
    'help' => t('Whether or not the forum_post is published.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Alter the forum_post.thread_status handler
  $data['brain_forum_forum_post']['thread_status'] = array(
    'title' => t('Thread is published'),
    'help' => t("Whether or not the forum_post's thread is published."),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Thread is published'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['brain_forum_thread']['table']['group'] = t('Forum thread');
  $data['brain_forum_thread']['table']['base'] = array(
    'field' => 'tid', // This is the identifier field for the view.
    'title' => t('Forum thread'),
    'help' => t('Forum thread.'),
    'weight' => -10,
  );
  $data['brain_forum_thread']['table']['entity type'] = 'thread';

  // Alter the forum_post pid handler
  $data['brain_forum_thread']['tid'] = array(
    'title' => t('Thread ID'),
    'help' => t('Thread ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array (
      'base' => 'brain_forum_forum_post',
      'field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Thread tid'),
    )
  );

  // Alter the forum_post title handler
  $data['brain_forum_thread']['title'] = array(
    'title' => t('Title'),
    'help' => t('Post title.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Alter the forum_post uid handler
  $data['brain_forum_thread']['uid'] = array(
    'title' => t('Author UID'),
    'help' => t('User ID.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_sort_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'relationship' => array(
      'title' => t('Author'),
      'help' => t("The User ID of the author's author."),
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('author'),
    ),
  );

  $data['brain_forum_thread']['name'] = array(
    'title' => t('Name'),
    'help' => t('The forum_post author name.'),
    'field' => array(
      'handler' => 'views_handler_field_user_name',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['brain_forum_thread']['created'] = array(
    'title' => t('Post date'),
    'help' => t('Date and time of when the post was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['brain_forum_thread']['last_pid'] = array(
    'title' => t('Last post'),
    'help' => t('The PID of the last post in the thread.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['brain_forum_thread']['last_uid'] = array(
    'title' => t('Last author UID'),
    'help' => t('User ID of the last post in the thread.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_sort_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
  );

  $data['brain_forum_thread']['last_name'] = array(
    'title' => t('Last author name'),
    'help' => t('User name of the author of the last post in the thread.'),
    'field' => array(
      'handler' => 'views_handler_field_user_name',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['brain_forum_thread']['last_time'] = array(
    'title' => t('Last post date'),
    'help' => t('Date of when the last post was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['brain_forum_thread']['forum_posts'] = array(
    'title' => t('Number of posts'),
    'help' => t('Number of forum_posts in the thread.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['brain_forum_thread']['views'] = array(
    'title' => t('Number of views'),
    'help' => t('Number of views of the thread.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['brain_forum_thread']['status'] = array(
    'title' => t('Thread is published'),
    'help' => t("Whether or not the forum_post's thread is published."),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Thread is published'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['brain_forum_thread']['closed'] = array(
    'title' => t('Thread is closed'),
    'help' => t("Whether or not the forum_post's thread is closed."),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Thread is closed'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_query_substitutions().
 */
function brain_forum_views_query_substitutions() {
  return array(
    '***ADMINISTER_FORUM_THREADS***' => intval(user_access('administer forum threads')),
    '***ADMINISTER_FORUM_POSTS***' => intval(user_access('administer forum forum_posts')),
    '***CREATE_FORUM_POSTS***' => intval(user_access('create forum forum_posts')),
    '***EDIT_FORUM_POSTS***' => intval(user_access('edit forum forum_posts')),
  );
}
