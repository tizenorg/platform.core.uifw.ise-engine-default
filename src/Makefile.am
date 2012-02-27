## Makefile.am -- Process this file with automake to produce Makefile.in
## Copyright (C) 2002 James Su
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2, or (at your option)
## any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

MAINTAINERCLEANFILES	= Makefile.in

default_DEFINES		= 	-DISF_ICONDIR=\"@ISF_ICONDIR@\" \
			  			-DISF_DEFAULT_LOCALEDIR=\"$(localedir)\" \
			  			-DISF_DEFAULT_DATADIR=\"@ISF_DEFAULT_DATADIR@\" \
			  			-DISF_DEFAULT_ICON_FILE=\"@ISF_ICONDIR@/isf-default.png\"

noinst_HEADERS		= 	isf_default_imengine.h\
						kdb_resource.h

moduledir			= 	@ISF_MODULEDIR@/IMEngine
module_LTLIBRARIES	= 	ise-engine-default.la


ise_engine_default_la_SOURCES 	= 	isf_default_imengine.cpp

ise_engine_default_la_CFLAGS		= 	@ISF_CFLAGS@ $(default_DEFINES)
ise_engine_default_la_CXXFLAGS	= 	@ISF_CFLAGS@ $(default_DEFINES)\
	                               	$(DEFAULT_CFLAGS)

ise_engine_default_la_LDFLAGS	= 	-avoid-version \
		     	  			-rpath $(moduledir) \
			  			-module \
			 			@LIBTOOL_EXPORT_OPTIONS@ \
			  			@ISF_LIBS@
