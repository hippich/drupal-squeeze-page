<?php
/**
 * Callback for drupal_get_form() to get the form for the admin/settings/squeeze page.
 */
function squeeze_admin_settings() {
  $form = array();
  $form['#submit'][] = 'squeeze_admin_settings_submit';
  $form['squeeze_settings_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Squeeze enabled content types'),
    '#description' => t('Squeeze allows you to restict its interception to specific content types. Choose the types on which you would like to use Squeeze. If you do not select any content type, Squeeze will be enabled for all content types.'),
    '#options' => node_get_types('names'),
    '#default_value' => variable_get('squeeze_settings_content_types', array()),
  );
  $form['squeeze_settings_anonymous_only'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show only for anonymous users'),
    '#default_value' => variable_get('squeeze_settings_anonymous_only', 0),
    '#description' => t('Check whether you want to show the Squeeze form only to anonymous users. This is equal to giving all roles the "@permission" permission at once, except the locked "@anonymous_user" role.',
       array('@permission' => t('skip squeeze page'), '@anonymous_user' => t('anonymous user'))),
  );
  return system_settings_form($form);
}

/**
 * Form submit callback for the admin_settings form.
 *
 * Processes the submitted form. Settings are handled by the default system
 * settings form handling, but we clean up the representation of supported
 * content types here before storing it in a variable.
 */
function squeeze_admin_settings_submit($form, &$form_state) {
  $form_state['values']['squeeze_settings_content_types'] = array_keys(array_filter($form_state['values']['squeeze_settings_content_types']));
}
