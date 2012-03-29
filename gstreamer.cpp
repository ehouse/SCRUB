#include "gstreamer.h"
#include "commandline.h"

GstElement *pipeline;
GMainLoop *loop;
GstBus *bus;

static gboolean bus_call(GstBus *bus, GstMessage *msg, void *user_data){
	switch (GST_MESSAGE_TYPE(msg)){
		case GST_MESSAGE_EOS:
			gst_element_set_state(GST_ELEMENT(pipeline),GST_STATE_NULL); //runs when song is over
			break;
		case GST_MESSAGE_ERROR:
			GError *err;
			gst_message_parse_error(msg,&err,NULL);
			g_error("%s", err->message); //needs fixing, fixed for ncurses
			g_error_free(err);
			g_main_loop_quit(loop);      //ABORT, ALL MEN TO THE STARBOARD BOW
			break;
		default:
			break;
	}
	return true;
}
bool init_gstreamer(){
	loop = g_main_loop_new(NULL,FALSE);  //creates loop to run through, it's pretty useful
	pipeline = gst_element_factory_make("playbin","player"); //creates a playbin player 
	bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline)); //random settings
	gst_bus_add_watch(bus,bus_call,NULL); //watch for end of song or interups
	gst_object_unref(bus); //bus isn't needed anymore
	g_main_loop_run(loop); //starts input loop, this freezes the thread until song is finished
	//gst_object_unref(GST_OBJECT(pipeline)); //really isn't needed, think this breaks things actually
	return true;
}
bool stop_song(){
	//pretty easy to understand
	gst_element_set_state(GST_ELEMENT(pipeline),GST_STATE_NULL);
	return true;
}
bool pause_song(){
	//pretty easy to understand
	gst_element_set_state(GST_ELEMENT(pipeline),GST_STATE_PAUSED);
	return true;
}
bool play_song(){
	//pretty easy to understand
	gst_element_set_state(GST_ELEMENT(pipeline),GST_STATE_PLAYING);
	return true;
}
bool set_song(char *uri){
	char location[1024] = "file://";
	strcat(location,uri);
	if(uri){
		g_object_set(G_OBJECT(pipeline),"uri",location,NULL);
		return true;
	}
	else{
		return false;
	}
}
