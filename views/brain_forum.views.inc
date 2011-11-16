<?php

/**
 * @file
 * Provides information about brain_forum entities to views.
 */

/**
 * Implements hook_views_data_alter().
 */
function brain_forum_views_data_alter(&$data) {
  // Alter the handler of post author name
  $data['brain_forum_post']['name']['field']['handler'] = 'views_handler_field_user_name';

  // Alter the handler of post author uid
  $data['brain_forum_post']['uid']['field']['handler'] = 'views_handler_field_user';
  $data['brain_forum_post']['uid']['filter']['title'] = t('Name');
  $data['brain_forum_post']['uid']['filter']['handler'] = 'views_handler_sort_user_name';
  $data['brain_forum_post']['uid']['argument']['handler'] = 'views_handler_argument_user_uid';

  // Alter the handler of thread author name
  $data['brain_forum_thread']['name']['field']['handler'] = 'views_handler_field_user_name';

  // Alter the handler of thread author uid
  $data['brain_forum_thread']['uid']['field']['handler'] = 'views_handler_field_user';
  $data['brain_forum_thread']['uid']['filter']['title'] = t('Name');
  $data['brain_forum_thread']['uid']['filter']['handler'] = 'views_handler_sort_user_name';
  $data['brain_forum_thread']['uid']['argument']['handler'] = 'views_handler_argument_user_uid';

  // Alter the post status handler
  $data['brain_forum_post']['status'] = array(
    'title' => t('Published'),
    'help' => t('Whether or not the post is published.'),
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

  // Alter the thread status handler
  $data['brain_forum_thread']['status'] = array(
    'title' => t('Published'),
    'help' => t('Whether or not the thread is published.'),
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

  // Add post published or admin field
  $data['brain_forum_post']['status_extra'] = array(
    'title' => t('Published or admin'),
    'help' => t('Filters out unpublished posts if the current user cannot view them.'),
    'filter' => array(
      'field' => 'status',
      'handler' => 'brain_forum_post_handler_filter_status',
      'label' => t('Published or admin'),
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


  // Add relationship to forum post based on the thread tid
  $data['brain_forum_thread']['tid']['relationship'] = array(
    'base' => 'brain_forum_post',
    'field' => 'tid',
    'handler' => 'views_handler_relationship',
    'label' => t('Thread tid'),
  );

  // Add relationship to forum thread based on the post tid
  $data['brain_forum_post']['tid']['relationship'] = array(
    'base' => 'brain_forum_thread',
    'field' => 'tid',
    'handler' => 'views_handler_relationship',
    'label' => t('Thread tid'),
  );

  // Add relationship to the users table based on the post uid
  $data['brain_forum_post']['uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'uid',
    'handler' => 'views_handler_relationship',
    'label' => t('Post author uid'),
  );

  // Add reply link field
  $data['brain_forum_post']['reply'] = array(
    'field' => array(
      'title' => t('Reply link'),
      'help' => t('Provide a reply link to the post.'),
      'handler' => 'brain_forum_post_handler_reply_field',
    ),
  );

  // Add quote link field
  $data['brain_forum_post']['quote'] = array(
    'field' => array(
      'title' => t('Quote link'),
      'help' => t('Provide a quote link to the post.'),
      'handler' => 'brain_forum_post_handler_quote_field',
    ),
  );

  // Add edit link field
  $data['brain_forum_post']['edit'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a edit link to the post.'),
      'handler' => 'brain_forum_post_handler_edit_field',
    ),
  );

}

/**
 * Implements hook_views_query_substitutions().
 */
function brain_forum_views_query_substitutions() {
  return array(
    '***ADMINISTER_FORUM_THREADS***' => intval(user_access('administer forum threads')),
    '***ADMINISTER_FORUM_POSTS***' => intval(user_access('administer forum posts')),
    '***CREATE_FORUM_POSTS***' => intval(user_access('create forum posts')),
    '***EDIT_FORUM_POSTS***' => intval(user_access('edit forum posts')),
  );
}
