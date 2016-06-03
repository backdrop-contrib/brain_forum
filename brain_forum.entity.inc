<?php
/**
 * @file
 * Certificate Settings entity classes.
 */

/**
 * Certificate Settings entity type class.
 */
class BrainForumPost extends Entity {
  public $pid;
  public $tid;
  public $is_first;
  public $title;
  public $uid;
  public $name;
  public $ip;
  public $created;
  public $changed;
  public $status;
  public $thread_status;

  function id() {
    return $this->pid;
  }

  public function entityType() {
    return 'forum_post';
  }

  function label() {
    return 'label';
  }

  function uri() {
    return array(
      'path' => 'forum_post/' . $this->pid,
    );
  }
}
/**
 * Certificate Settings entity type class.
 */
class BrainForumThread extends Entity {
  public $tid;
  public $title;
  public $uid;
  public $name;
  public $created;
  public $last_pid;
  public $last_uid;
  public $last_name;
  public $last_time;
  public $forum_posts;
  public $views;
  public $status;
  public $closed;

  function id() {
    return $this->tid;
  }

  public function entityType() {
    return 'thread';
  }

  function label() {
    return 'label';
  }

  function uri() {
    return array(
      'path' => 'thread/' . $this->tid,
    );
  }
}

