VisualDCT 3.0 beta 2009-10-15

RELEASE NOTES

1. Release contents

vdct_3-0-b.jar - executable jar containing Visual DCT application bundled with all its dependent libraries

vdct_pvdata_example.sh - example unix execution script

vdct_db_example.sh - example unix execution script

vdct_pvdata_example.bat - example MSWindows execution script

vdct_db_example.bat - example MSWindows execution script

MAN-VDCT3.pdf - VisualDCT manual

README.txt - this file

config/db - configuration folder containing example configuration files for  db (epics3) module (including the IRMIS plugin)

config/pvdata - configuration folder containing example configuration files for pvdata (epics4) module

example/db - folder containing example dbd and db model files

example/pvdata - folder containing example xml pvdata model files.

capfastlib - folder containing capfast epics symbol library


2. System requirements

This release has been tested on Java 1.6.0 under the following system configurations:
-Windows XP 2002 SP2
-Apple OS X 10.5.6, 1.0.6
-Debian, Ubuntu Linux


3. How to run the product

Convenience Unix and MSWindows shell script files for executing and preloading model files are bundled with the distribution as well as some example model files:
- vdct_pvdata_example.sh (bat) - loads pvdata configuration and an example model file
- vdct_db_example.sh (bat) - loads db configuration and an example model file

The jar vdct_3-0-b.jar can be manualy executed with

java -jar vdct_3-0-b.jar

it loads a default configuration (it is saved in the user's home folder) and no model file.

WARNING: If no default configuration exists, a new one is created and application defaults are loaded. 
Make sure you configure your module dependencies properly, before opening model files.

To use a specified config folder add the -config parameter, followed by the path to the config folder, e.g.

java -jar vdct_3-0-b.jar -config config/db

To preload a model file, just add its path as a parameter to the java command

java -jar vdct_3-0-b.jar example/db/airc_example.db

WARNING: Make sure your configuration (default or specified) loads a compatible module with all the required static includes (e.g. dbd's).

To open a remote IRMIS db location, load the db module and choose the "Load IOC from IRMIS..." option in the Module menu. Remote IRMIS service location and IOC name have to be provided.


4. Release Features (New compared to previous release)

4.1 General

- hieararchy view
- drawing of graphic primitives
- grouping of properties/fields in proeprty editors
- dedicated property editors for known field types (enum, number)
- property editors entry value validation
- naming convention specification & validation
- improved copy/paste support (mutliple select, multiple paste)
- bird view magnification on cursor
- zoom all, select all
- auto de-cluttering of widgets on canvas
- snap-to-grid
- print canvas

4.2 db with IRMIS

- integration of CapFast epics symbol library
- record morphing support
- bugfix: Loading of multiple records from IRMIS failed

4.3 pvdata

- improved link support


5. Previous Releases

VisualDCT 3.0 alpha 2009-06-30

Release Features

.1 General:
- Copy/Cut/Paste
- Mutliple Undo/Redo
- Drag & Drop moving of nodes
- Spreadsheet view
- Property inspector
- Local configuration support
- Custom widgets per module, customize widget colors
- Keyboard accelerator key shortcuts

.2 pvdata specific functionality:

I/O
- open file
- import file into existing model
- save/save as file

Editing
- static includes (edit, inspect)
- new record (types)
- add/remove/set/unset fields (scalars, structures)
- add/remove links
- view/edit substructures (hierarchy support)
- edit/inspect includes

.3 db specific functionality:

I/O
- open file
- import file into existing model
- save/save as file

Editing
- handling of dbd includes
- new record (types)
- set/unset fields
- add/remove links

IRMIS
- open single IOC from remote db location