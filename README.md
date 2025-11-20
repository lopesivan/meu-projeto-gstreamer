pip install conan
make rebuild
make run ARGS=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm




O erro “Erro ao criar pipeline” **não vem do linker**, mas do `gst_parse_launch` que devolveu `nullptr`.  
As causas mais comuns são:

1. **Faltam plugins base/good/ugly/bad** (ou o playbin não foi encontrado).  
2. **Falta DISPLAY** (se estiver via ssh sem X11) – mas isso geraria outra mensagem.  
3. **A URL está incompleta ou mal escapada** (não é o caso aqui).  
4. **Falta o plugin `httpsrc`** (ou `souphttpsrc`) para download HTTP.

Verifique e instale os pacotes que faltam:

```bash
# Ubuntu/Debian
sudo apt update
sudo apt install gstreamer1.0-plugins-base \
                 gstreamer1.0-plugins-good \
                 gstreamer1.0-plugins-bad \
                 gstreamer1.0-plugins-ugly \
                 gstreamer1.0-libav
```

Depois rode novamente:

```bash
make run ARGS=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm
```

Se **não houver DISPLAY** (ambiente headless), teste com um arquivo local **.webm/.mp4** e force modo **fake-video-sink**:

```bash
make run ARGS=file:///tmp/video.mp4
```

ou altere o pipeline em `main.cpp` para:

```cpp
GstElement *pipeline = gst_parse_launch(
    ("playbin uri=" + std::string(argv[1]) +
     " video-sink=fakesink audio-sink=fakesink").c_str(), nullptr);
```

Isso evita janelas e ainda confirma se o playbin está funcionando.

