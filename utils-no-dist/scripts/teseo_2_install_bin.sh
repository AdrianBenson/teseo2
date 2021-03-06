#!/bin/sh

# Teseo-2 binary installation script for UNIX system (Linux, MAC OS X, ...)
# This distribution should contain:
#	- teseo-2 (binary plug-in)
#	- README
#	- NEWS
#	- AUTHORS
#	- COPYING

# Teseo-2 GIMP Plug-in
# Copyright (C) 2005-2019  Stefano Pintore, Matteo Quintiliani (the "Authors").
# All Rights Reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE Authors BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# Except as contained in this notice, the name of the Authors of the
# Software shall not be used in advertising or otherwise to promote the
# sale, use or other dealings in this Software without prior written
# authorization from the Authors.


GIMPVER="2.2"
DIRGIMP="$HOME/.gimp-$GIMPVER"
DIRGIMPPLUGINS="$DIRGIMP/plug-ins"
DIRNAME=$(dirname $0)
TESEOBIN=$DIRNAME/teseo-2
TESEOBINDESTINATION=$DIRGIMPPLUGINS/teseo-2

echo ""

if [ -d $DIRGIMP ]; then
    if [ -d $DIRGIMPPLUGINS ]; then
	cp $TESEOBIN $TESEOBINDESTINATION   &&   echo "Teseo-2 has been installed. Gimp must be restarded !!!"
    else
        echo "I can't find GIMP folder plug-ins '$DIRGIMPPLUGINS' !"
    fi
else
   echo "I can't find GIMP folder '$DIRGIMP' !"
   echo "This Teseo-2 distribution works with GIMP $GIMPVER"
fi

echo ""

