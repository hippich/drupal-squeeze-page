<?php
/**
 * Callback for drupal_get_form() to get the form for the admin/settings/squeeze page.
 */
function squeeze_admin_settings() {
  $form = array();

  $form['squeeze_settings_anonymous_only'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show only for anonymous users'),
    '#default_value' => variable_get('squeeze_settings_anonymous_only', 0),
    '#description' => t('Check whether you want to show the Squeeze form only to anonymous users. This is equal to giving all roles the "@permission" permission at once, except the locked "@anonymous_user" role.',
       array('@permission' => t('skip squeeze page'), '@anonymous_user' => t('anonymous user'))),
  );

  return system_settings_form($form);
}
