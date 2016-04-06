This branch adds support for [libToxTun](https://github.com/ddorian1/libtoxtun) to qTox.

To enable support for libToxTun, you need to run qmake with "ENABLE_TOXTUN=YES".

## Usage notes
### Linux
You need a kernel with tun support (ether build in or as modul "tun").
Since the library needs to set up the tun interface, it needs to by run as root (NOT recommended) or with the CAP_NET_ADMIN capabilitie set. To do so, run
```sudo setcap cap_net_admin=ep FOO```
replacing FOO with your aplication.

###Windows
For windows, you need the tuntap driver of the openvpn project, found [here](https://openvpn.net/index.php/open-source/downloads.html) (look for Tap-windows), and of cause one unused virtual device created.

[**Compile**](/INSTALL.md)
