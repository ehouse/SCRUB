#ifndef GSTREAMER_GUARD_H
#define GSTREAMER_GUARD_H

#include <gst/gst.h>
#include <stdbool.h>
#include <ncurses.h>
#include <string.h>

bool init_gstreamer();
//static gboolean bus_call(GstBus *bus, GstMessage *msg, void *user_data);
bool stop_song();
bool pause_song();
bool play_song();
bool set_song(char *uri);

#endif
