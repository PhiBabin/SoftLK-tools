
.POSIX:
CC      = emcc
CFLAGS  = -Wall -Wextra -Wshadow -std=gnu99 -Wno-sign-compare -Wconversion -Wno-sign-conversion -Wno-unused -O3 -g -fno-omit-frame-pointer -I../HLH_gui/ -I../3rd/ -I../ -lm -I. -s USE_SDL=2 -sEXPORTED_RUNTIME_METHODS=[ccall]
LDFLAGS =
LDLIBS  = 
all: img2pix index_html
tint.o: tint.c ../HLH_gui/HLH.h ../shared/color.h img2pixel.h \
 ../shared/image.h
sharp.o: sharp.c ../HLH_gui/HLH.h ../shared/color.h img2pixel.h \
 ../shared/image.h
sample.o: sample.c ../HLH_gui/HLH.h ../shared/image.h ../shared/color.h \
 img2pixel.h
postprocess.o: postprocess.c ../HLH_gui/HLH.h ../shared/color.h \
 img2pixel.h ../shared/image.h
palette.o: palette.c ../HLH_gui/HLH_gui.h ../HLH_gui/HLH.h \
 ../shared/color.h img2pixel.h ../shared/image.h
kmeans.o: kmeans.c ../external/HLH.h ../shared/color.h img2pixel.h \
 ../shared/image.h
hscb.o: hscb.c ../HLH_gui/HLH.h ../shared/color.h img2pixel.h \
 ../shared/image.h
gui.o: gui.c ../3rd/cute_files.h ../HLH_gui/HLH_gui.h ../HLH_gui/HLH.h \
 ../HLH_gui/HLH_path.h ../HLH_gui/HLH_json.h ../shared/color.h \
 ../shared/image.h img2pixel.h util.h gui.h
gamma.o: gamma.c ../HLH_gui/HLH.h ../shared/color.h img2pixel.h \
 ../shared/image.h
dither.o: dither.c ../HLH_gui/HLH.h ../shared/color.h ../shared/image.h \
 img2pixel.h
blur.o: blur.c ../HLH_gui/HLH.h img2pixel.h ../shared/image.h
../shared/rand.o: ../shared/rand.c ../HLH_gui/HLH.h ../shared/rand.h
../shared/png.o: ../shared/png.c ../HLH_gui/HLH_gui.h ../3rd/rpng.h \
 ../shared/color.h ../shared/png.h ../shared/image.h
../shared/pcx.o: ../shared/pcx.c ../HLH_gui/HLH.h ../HLH_gui/HLH_rw.h \
 ../shared/color.h ../shared/pcx.h ../shared/image.h
../shared/image.o: ../shared/image.c ../HLH_gui/HLH.h ../shared/image.h \
 ../shared/color.h ../shared/rand.h ../shared/pcx.h ../shared/png.h
../shared/color.o: ../shared/color.c ../HLH_gui/HLH_gui.h \
 ../HLH_gui/HLH.h ../shared/color.h
../external/tinyfiledialogs.o: ../external/tinyfiledialogs.c \
 ../external/tinyfiledialogs.h
../external/emscripten_browser_file.o: ../external/emscripten_browser_file.c \
 ../external/emscripten_browser_file.h
../HLH_gui/HLH_gui_all.o: ../HLH_gui/HLH_gui_all.c ../HLH_gui/HLH_gui.h \
 ../HLH_gui/HLH_gui_core.c ../HLH_gui/stb_image.h \
 ../HLH_gui/stb_image_write.h ../HLH_gui/HLH.h \
 ../HLH_gui/HLH_gui_internal.h ../HLH_gui/HLH_gui_element.c \
 ../HLH_gui/HLH_gui_rect.c ../HLH_gui/HLH_gui_point.c \
 ../HLH_gui/HLH_gui_draw.c ../HLH_gui/HLH_gui_group.c \
 ../HLH_gui/HLH_gui_label.c ../HLH_gui/HLH_gui_button.c \
 ../HLH_gui/HLH_gui_checkbutton.c ../HLH_gui/HLH_gui_radiobutton.c \
 ../HLH_gui/HLH_gui_menu.c ../HLH_gui/HLH_gui_menubar.c \
 ../HLH_gui/HLH_gui_separator.c ../HLH_gui/HLH_gui_slider.c \
 ../HLH_gui/HLH_gui_image.c ../HLH_gui/HLH_gui_imgcmp.c \
 ../HLH_gui/HLH_gui_entry.c
unix/util_unix.o: unix/util_unix.c ../HLH_gui/HLH_gui.h \
 ../HLH_gui/HLH_json.h unix/../../external/tinyfiledialogs.h \
 unix/../img2pixel.h ../shared/image.h unix/../util.h
obj=  ./tint.o ./sharp.o ./sample.o ./postprocess.o ./palette.o ./kmeans.o ./hscb.o ./gui.o ./gamma.o ./dither.o ./blur.o ../shared/rand.o ../shared/png.o ../shared/pcx.o ../shared/image.o ../shared/color.o ../external/tinyfiledialogs.o ../external/emscripten_browser_file.o ../HLH_gui/HLH_gui_all.o unix/util_unix.o
main/main.o: main/main.c ../HLH_gui/HLH.h ../HLH_gui/HLH_path.h \
 ../HLH_gui/HLH_rw.h ../HLH_gui/HLH_json.h \
 main/../../external/fopen_utf8.h ../3rd/cute_files.h \
 ../HLH_gui/HLH_gui.h img2pixel.h ../shared/image.h util.h gui.h  ../external/emscripten_browser_file.h
img2pix: $(obj) main/main.o
	$(CC) -o ../bin/SLK_img2pix.html $^ -Wall -Wextra -Wshadow -std=gnu99 -Wno-sign-compare -Wconversion -Wno-sign-conversion -Wno-unused -sALLOW_MEMORY_GROWTH=1 -O3 -g -fno-omit-frame-pointer -I../HLH_gui/ -I../3rd/ -I../ -lm  -I. -lSDL2 -sEXPORTED_FUNCTIONS=[_load_file,_main,_upload_file_return] -sEXPORTED_RUNTIME_METHODS=[ccall,cwrap] --preload-file asset_dir
index_html:
	cp html/* ../bin
clean:
	rm -f $(obj) main/*.o ../bin/SLK_img2pix.js ../bin/SLK_img2pix_cmd.js ../bin/index.html
