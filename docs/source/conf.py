# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'DoxySphinx'
copyright = '2026, Austin Schuberth'
author = 'Austin Schuberth'
release = '0.1.0'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

import subprocess, os


breathe_projects = {}

read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

if read_the_docs_build:

     subprocess.call('cd ..;doxygen', shell=True)
     breathe_projects['doxysphinx'] = '../build/xml'



extensions = ['breathe']

templates_path = ['_templates']
exclude_patterns = []



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_book_theme'
html_static_path = ['_static']

# Breathe
breathe_default_project = "doxysphinx"

