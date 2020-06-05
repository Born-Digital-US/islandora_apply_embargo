# Islandora Apply Embargo

## Introduction

This module provides the ability to automatically apply embargos to objects when ingested, based on metadata provided in the
MODS datastream.

This module only affects objects during initial ingest, and not when updated.


## Requirements and Installation

Download this module, the Islandora Scholar module, and its respective dependencies, and place them under your modules folder.
* [Islandora Scholar](https://github.com/islandora/islandora_scholar)

Enable `islandora_apply_embargo`, `islandora_scholar_embargo`, `islandora_scholar`, and any further dependencies that they require.


## Configuration

An xpath expression that finds embargo dates in MODS xml needs to be provided. If the bd_ui module is enabled, a tab for configuring this
xpath is displayed on the BD Settings form at `/admin/config/bd`. If the BD UI module is not availabe, this value can be inserted into
the drupal variables through one of two methods:

* In from the command line, use `drush vset islandora_apply_embargo_mods_xpath '<the xpath>'`
* In `settings.php`, add a line `$conf['islandora_apply_embargo_mods_xpath'] = '<the xpath>';`

The xpath that you choose must include `mods` namespacing as can be seen in the following example.

* `//mods:originInfo/mods:dateOther[@type="embargoDate"]`

### Usage

To apply embargos to objects upon ingest, whether they are manually ingested or ingested by batch methods such as IMI, two conditions need to be met:
* This module needs to be enabled and configured with an xpath.
* The incoming object must have a MODS datastream that contains the embargo date at the xpath configured in the settings for this module.

**The embargo date value in the MODS metadata must be a valid xsd:DateTime string, or the word 'indefinite'.**

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* [Pat Dunlavey](https://github.com/patdunlavey)
* [Born-Digital](https://github.com/Born-Digital-US)

## Development

If you would like to contribute to this module, please check out [CONTRIBUTING.md](CONTRIBUTING.md). In addition, we have helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the [Islandora.ca](http://islandora.ca) site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)

