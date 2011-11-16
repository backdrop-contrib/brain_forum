<?php

/**
 * @file
 * Creates default views for the brain_forum module.
 */

/**
 * Implements hook_views_default_views().
 */
function brain_forum_views_default_views() {
  $views = array();

  // Begin copy and paste of output from the Export tab of a view.
  $view = new view;
  $view->name = 'forum_listing';
  $view->description = 'Lists all threads and information about the last post in each thread';
  $view->tag = 'brain_forum';
  $view->base_table = 'brain_forum_thread';
  $view->human_name = 'Forum listing';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'forum-thread-list';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view forum thread list';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'views' => 'views',
    'last_time' => 'last_time',
    'posts' => 'posts',
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No forum threads have been created yet in this category.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Forum thread: Forum thread ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'brain_forum_thread';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['tid']['format_plural'] = 0;
  /* Field: Forum thread: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'brain_forum_thread';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'forum/thread/[tid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'forum-thread-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  /* Field: Forum thread: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'brain_forum_thread';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Forum thread: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'brain_forum_thread';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_class'] = 'forum-thread-author';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Forum thread: Views */
  $handler->display->display_options['fields']['views']['id'] = 'views';
  $handler->display->display_options['fields']['views']['table'] = 'brain_forum_thread';
  $handler->display->display_options['fields']['views']['field'] = 'views';
  $handler->display->display_options['fields']['views']['label'] = '';
  $handler->display->display_options['fields']['views']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views']['format_plural'] = 0;
  $handler->display->display_options['fields']['views']['prefix'] = 'Read ';
  $handler->display->display_options['fields']['views']['suffix'] = ' times';
  /* Field: Forum thread: Posts */
  $handler->display->display_options['fields']['posts']['id'] = 'posts';
  $handler->display->display_options['fields']['posts']['table'] = 'brain_forum_thread';
  $handler->display->display_options['fields']['posts']['field'] = 'posts';
  $handler->display->display_options['fields']['posts']['label'] = '';
  $handler->display->display_options['fields']['posts']['exclude'] = TRUE;
  $handler->display->display_options['fields']['posts']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['posts']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['posts']['alter']['path'] = 'forum/thread/[tid]';
  $handler->display->display_options['fields']['posts']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['posts']['alter']['external'] = 0;
  $handler->display->display_options['fields']['posts']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['posts']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['posts']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['posts']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['posts']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['posts']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['posts']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['posts']['alter']['html'] = 0;
  $handler->display->display_options['fields']['posts']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['posts']['element_wrapper_class'] = 'forum-thread-stats';
  $handler->display->display_options['fields']['posts']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['posts']['hide_empty'] = 0;
  $handler->display->display_options['fields']['posts']['empty_zero'] = 0;
  $handler->display->display_options['fields']['posts']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['posts']['format_plural'] = 0;
  $handler->display->display_options['fields']['posts']['suffix'] = ' replies';
  /* Field: Forum thread: Last post date */
  $handler->display->display_options['fields']['last_time']['id'] = 'last_time';
  $handler->display->display_options['fields']['last_time']['table'] = 'brain_forum_thread';
  $handler->display->display_options['fields']['last_time']['field'] = 'last_time';
  $handler->display->display_options['fields']['last_time']['label'] = '';
  $handler->display->display_options['fields']['last_time']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['last_time']['alter']['text'] = '[posts] (latest [last_time])';
  $handler->display->display_options['fields']['last_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['last_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['last_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['last_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['last_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['last_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['last_time']['hide_empty'] = 1;
  $handler->display->display_options['fields']['last_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_time']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['last_time']['date_format'] = 'long';
  /* Sort criterion: Forum thread: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'brain_forum_thread';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Forum thread: Category (forum_category) */
  $handler->display->display_options['arguments']['forum_category_tid']['id'] = 'forum_category_tid';
  $handler->display->display_options['arguments']['forum_category_tid']['table'] = 'field_data_forum_category';
  $handler->display->display_options['arguments']['forum_category_tid']['field'] = 'forum_category_tid';
  $handler->display->display_options['arguments']['forum_category_tid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['forum_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['forum_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['forum_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['forum_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['forum_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['forum_category_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['forum_category_tid']['not'] = 0;
  /* Filter criterion: Forum thread: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'brain_forum_thread';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'forum';
  $translatables['forum_listing'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No forum threads have been created yet in this category.'),
    t('.'),
    t(','),
    t('forum/thread/[tid]'),
    t('Read '),
    t(' times'),
    t(' replies'),
    t('[posts] (latest [last_time])'),
    t('All'),
    t('Page'),
  );
  // End copy and paste of Export tab output.

  // Add view to list of views to provide if it doesn't already exist.
  if (!views_get_view($view->name)) {
    $views[$view->name] = $view;
  }

  // ...Repeat all of the above for each view the module should provide.

  // Begin copy and paste of output from the Export tab of a view.
  $view = new view;
  $view->name = 'forum_thread';
  $view->description = 'Show all posts paged in a forum thread';
  $view->tag = 'brain_forum';
  $view->base_table = 'brain_forum_post';
  $view->human_name = 'Forum thread';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'forum-thread';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view forum threads';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'created' => 'created',
    'edit' => 'edit',
    'reply' => 'reply',
    'quote' => 'quote',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'The thread could not be found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Forum post: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'brain_forum_post';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Forum post: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'brain_forum_post';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_class'] = 'forum-thread-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  /* Field: Forum post: Forum post ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'brain_forum_post';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['pid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['pid']['format_plural'] = 0;
  /* Field: Forum post: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'brain_forum_post';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: Forum post: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'brain_forum_post';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_class'] = 'author';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Forum post: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'brain_forum_post';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_wrapper_class'] = 'forum-thread-author';
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 0;
  /* Field: Forum post: Message */
  $handler->display->display_options['fields']['forum_post_message']['id'] = 'forum_post_message';
  $handler->display->display_options['fields']['forum_post_message']['table'] = 'field_data_forum_post_message';
  $handler->display->display_options['fields']['forum_post_message']['field'] = 'forum_post_message';
  $handler->display->display_options['fields']['forum_post_message']['label'] = '';
  $handler->display->display_options['fields']['forum_post_message']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['external'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['forum_post_message']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['forum_post_message']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['alter']['html'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['forum_post_message']['element_wrapper_class'] = 'forum-thread-message';
  $handler->display->display_options['fields']['forum_post_message']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['forum_post_message']['hide_empty'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['empty_zero'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['forum_post_message']['field_api_classes'] = 0;
  /* Field: Forum post: Edit link */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'brain_forum_post';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['label'] = '';
  $handler->display->display_options['fields']['edit']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit']['element_wrapper_class'] = 'forum-thread-links';
  $handler->display->display_options['fields']['edit']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit']['hide_empty'] = 1;
  $handler->display->display_options['fields']['edit']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit']['text'] = 'edit';
  /* Field: Forum post: Reply link */
  $handler->display->display_options['fields']['reply']['id'] = 'reply';
  $handler->display->display_options['fields']['reply']['table'] = 'brain_forum_post';
  $handler->display->display_options['fields']['reply']['field'] = 'reply';
  $handler->display->display_options['fields']['reply']['label'] = '';
  $handler->display->display_options['fields']['reply']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['external'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['reply']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['reply']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['reply']['alter']['html'] = 0;
  $handler->display->display_options['fields']['reply']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['reply']['element_wrapper_class'] = 'forum-thread-links';
  $handler->display->display_options['fields']['reply']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['reply']['hide_empty'] = 1;
  $handler->display->display_options['fields']['reply']['empty_zero'] = 0;
  $handler->display->display_options['fields']['reply']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['reply']['text'] = 'reply';
  /* Field: Forum post: Quote link */
  $handler->display->display_options['fields']['quote']['id'] = 'quote';
  $handler->display->display_options['fields']['quote']['table'] = 'brain_forum_post';
  $handler->display->display_options['fields']['quote']['field'] = 'quote';
  $handler->display->display_options['fields']['quote']['label'] = '';
  $handler->display->display_options['fields']['quote']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['quote']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['quote']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['quote']['alter']['external'] = 0;
  $handler->display->display_options['fields']['quote']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['quote']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['quote']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['quote']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['quote']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['quote']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['quote']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['quote']['alter']['html'] = 0;
  $handler->display->display_options['fields']['quote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['quote']['element_wrapper_class'] = 'forum-thread-links';
  $handler->display->display_options['fields']['quote']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['quote']['hide_empty'] = 1;
  $handler->display->display_options['fields']['quote']['empty_zero'] = 0;
  $handler->display->display_options['fields']['quote']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['quote']['text'] = 'quote';
  /* Sort criterion: Forum post: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'brain_forum_post';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: Forum post: Tid */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'brain_forum_post';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['not'] = 0;
  /* Filter criterion: Forum post: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'brain_forum_post';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['display_description'] = 'Show all posts paged in a forum thread selected by contextual filter';
  $handler->display->display_options['path'] = 'forum/thread/%';
  $translatables['forum_thread'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('The thread could not be found.'),
    t('Post author uid'),
    t('.'),
    t(','),
    t('user/[uid]'),
    t('edit'),
    t('reply'),
    t('quote'),
    t('All'),
    t('Page'),
    t('Show all posts paged in a forum thread selected by contextual filter'),
  );
  // End copy and paste of Export tab output.

  // Add view to list of views to provide if it doesn't already exist.
  if (!views_get_view($view->name)) {
    $views[$view->name] = $view;
  }

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  return $views;
}
