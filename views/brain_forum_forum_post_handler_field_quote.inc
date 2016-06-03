<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying quote links to
 * forum forum_posts as fields.
 */

class brain_forum_forum_post_handler_quote_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['tid'] = 'tid';

  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array(
      'default' => '',
      'translatable' => TRUE,
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Get current path
    $current_path = $_GET['q'];

    // Get text from view field settings form.
    $text = !empty($this->options['text']) ? $this->options['text'] : t('quote');

    $tid = $values->{$this->aliases['tid']};
    $pid = $values->pid;

    // Calculate which is the last page of this view.
    $last_page = $last_page = $GLOBALS['pager_total'][0]-1;

    // Build the quote link anchored to the reply form.
    // If there is only one page, don't include query '?page=x' in the link.
    // @todo Replace hardcoded path with dynamically fetched one.
    $return = ($last_page == -0) ? l($text, $current_path, array('query' => array('quote' => $pid), 'fragment' => 'brain-forum-forum_post-add-form')) : l($text, $current_path, array('query' => array('page' => $last_page, 'quote' => $pid), 'fragment' => 'brain-forum-forum_post-add-form'));

    // Return link only if user has permission to create forum_posts
    if (user_access('create forum forum_posts') && user_access('use text format bbcode') && filter_format_exists('bbcode')) {
      return $return;
    }
  }
}
