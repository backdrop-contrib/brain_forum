<?php

/**
 * @file
 * Contains a Views filter handler to take care of filtering content by status.
 */
class brain_forum_thread_handler_filter_status extends views_handler_filter {
  function admin_summary() { }
  function operator_form(&$form, &$form_state) { }
  function can_expose() { return FALSE; }

  function query() {
    $table = $this->ensure_my_table();
    $this->query->add_where_expression($this->options['group'], "$table.status = 1 OR ***ADMINISTER_FORUM_THREADS*** = 1");
  }
}
