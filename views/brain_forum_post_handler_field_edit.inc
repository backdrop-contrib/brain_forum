<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links to
 * forum posts as fields.
 */

class brain_forum_post_handler_edit_field extends views_handler_field {
  function construct() {
    parent::construct();
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
    // Get text from view field settings form.
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    $pid = $values->pid;
    $destination = drupal_get_destination();

    // Build the edit link.
    // @todo Replace hardcoded path with dynamically fetched one.
    $return = l($text, 'forum/post/' . $pid . '/edit', array('query' => array('destination' => $destination['destination'])));

    // Return link only if user has permission to edit posts
    if (user_access('edit forum posts')) {
      return $return;
    }
  }
}
