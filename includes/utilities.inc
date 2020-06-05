<?php

function islandora_apply_embargo($object) {
  module_load_include('inc', 'islandora_scholar_embargo', 'includes/embargo');
  $existing_embargoes = islandora_scholar_embargo_get_embargoed($object);
  $embargoes = islandora_apply_embargo_get_embargo_from_object($object);
  if(!empty($embargoes)) {
    // Convert to xsd:DateTime format.
    $end = new DateTime(reset($embargoes));
    if(!empty($existing_embargoes[0]['date']['value']) ) {
      $existing_end = new DateTime($existing_embargoes[0]['date']['value']);
      if($end == $existing_end) {
        return;
      }
    }
    islandora_scholar_embargo_set_embargo($object, NULL, $end->format(\DateTime::RFC3339));
  }
}

/**
 * Get the embargo date or dates, if present.
 *
 * @return array
 *   An array containing 0, 1, or many embargo dates.
 */
function islandora_apply_embargo_get_embargo_from_object($object) {
  $embargoes = array();
  $embargo_xpath = variable_get('islandora_apply_embargo_mods_xpath', FALSE);
  // Example: '//mods:originInfo/mods:dateOther[@type="embargoDate"]'
  if(!empty($embargo_xpath) && !empty($object['MODS'])) {
    $mods = $object['MODS']->content;
    $mods_dom = new DOMDocument();
    $mods_dom->loadXML($mods);
    $mods_xpath = new DOMXPath($mods_dom);
    $mods_xpath->registerNamespace('mods', "http://www.loc.gov/mods/v3");
    $items = $mods_xpath->query($embargo_xpath);
    foreach($items as $item) {
      $embargoes[] = $item->nodeValue;
    }
  }

  return $embargoes;
}
