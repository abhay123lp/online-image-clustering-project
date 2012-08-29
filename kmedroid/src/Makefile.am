# Copyright (C) 2006-2012 Free Software Foundation, Inc.
# This Makefile.am is free software; the Free Software Foundation
# gives unlimited permission to copy, distribute and modify it.

PROTO_OUTPUT = cluster_message.pb.cc cluster_message.pb.h
PROTO = cluster_message.proto
$(PROTO_OUTPUT) : $(PROTO)
	protoc --cpp_out=. $^

BUILT_SOURCES = $(PROTO_OUTPUT)
CLEANFILES = $(PROTO_OUTPUT)

AM_LDFLAGS = -lprotoc -lpthread -lgtest -L../../lib/gtest-1.6.0/lib
AM_CPPFLAGS = -I../../lib/gtest-1.6.0/include

lib_LTLIBRARIES = lib_distance_matrix.la lib_cluster.la lib_cluster_message.la
lib_distance_matrix_la_SOURCES = distance_matrix.cc
lib_cluster_la_SOURCES = cluster.cc
lib_cluster_message_la_SOURCES = cluster_message.pb.cc

bin_PROGRAMS = distance_matrix_test cluster_test
distance_matrix_test_SOURCES = distance_matrix_test.cc 
distance_matrix_test_LDADD = lib_distance_matrix.la

cluster_test_SOURCES = cluster_test.cc
cluster_test_LDADD = lib_distance_matrix.la lib_cluster.la

TESTS = distance_matrix_test cluster_test
