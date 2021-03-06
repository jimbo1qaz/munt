// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "fl_munt_ui.h"

void FLMuntUI::cb_Reset_i(Fl_Button*, void*) {
  c->resetSynth();
}
void FLMuntUI::cb_Reset(Fl_Button* o, void* v) {
  ((FLMuntUI*)(o->parent()->user_data()))->cb_Reset_i(o,v);
}

void FLMuntUI::cb_Load_i(Fl_Button*, void*) {
  fc->show();
}
void FLMuntUI::cb_Load(Fl_Button* o, void* v) {
  ((FLMuntUI*)(o->parent()->user_data()))->cb_Load_i(o,v);
}

Fl_Double_Window* FLMuntUI::make_window() {
  { w = new Fl_Double_Window(430, 85);
    w->user_data((void*)(this));
    { Fl_Button* o = new Fl_Button(335, 15, 80, 25, "Reset");
      o->tooltip("Reset the synthesizer. This resets the state to factory settings.");
      o->callback((Fl_Callback*)cb_Reset);
    } // Fl_Button* o
    { display = new LCDDisplay(45, 46, 244, 24, "Display");
      display->box(FL_NO_BOX);
      display->color(FL_BACKGROUND_COLOR);
      display->selection_color(FL_BACKGROUND_COLOR);
      display->labeltype(FL_NORMAL_LABEL);
      display->labelfont(0);
      display->labelsize(14);
      display->labelcolor(FL_FOREGROUND_COLOR);
      display->align(Fl_Align(FL_ALIGN_CENTER));
      display->when(FL_WHEN_RELEASE);
    } // LCDDisplay* display
    { new Fl_Box(100, 14, 140, 21, "MT32EMU");
    } // Fl_Box* o
    { Fl_Button* o = new Fl_Button(335, 45, 80, 25, "Load syx");
      o->tooltip("Load a MT-32 SysEx (.syx) file");
      o->callback((Fl_Callback*)cb_Load);
    } // Fl_Button* o
    w->end();
  } // Fl_Double_Window* w
  fc = new Fl_File_Chooser(0, "MT32 SysEx files (*.syx)", Fl_File_Chooser::SINGLE, "Select .syx file to load");
  fc->callback(fc_callback, this);
  return w;
}

FLMuntUI::FLMuntUI(MuntUIController *controller) {
  make_window();
  w->show();
  c = controller;
}

FLMuntUI::~FLMuntUI() {
  delete w;
  delete fc;
}

FLMuntUI::FLMuntUI(MuntUIController *controller, void* parentWindow) {
  make_window();
  fl_open_display();
  fl_embed(w, (Window)parentWindow);
  c = controller;
}

void FLMuntUI::fc_callback(Fl_File_Chooser *fc, void *self) {
  if (fc->shown())
      return;
  const char *filename = fc->value();
  static_cast<FLMuntUI*>(self)->c->loadSyx(filename);
}

void FLMuntUI::load_syx(const char *filename) {
  printf("Hello, World! %s\n", filename);
}
