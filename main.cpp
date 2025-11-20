// main.cpp (mini pipeline: playbin → play → stop)
#include <gst/gst.h>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Uso: " << argv[0] << " <arquivo-ou-url>\n";
    return 0;
  }

  gst_init(&argc, &argv);

  GstElement *pipeline = gst_parse_launch(
      ("playbin uri=" + std::string(argv[1])).c_str(), nullptr);
  if (!pipeline) {
    std::cerr << "Erro ao criar pipeline\n";
    return 1;
  }

  gst_element_set_state(pipeline, GST_STATE_PLAYING);

  std::cout << "Tocando… (Ctrl+C para parar)\n";
  g_main_loop_run(g_main_loop_new(nullptr, FALSE));

  gst_element_set_state(pipeline, GST_STATE_NULL);
  gst_object_unref(pipeline);
  gst_deinit();
  return 0;
}
