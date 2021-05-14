# xkblayout-subscribe

simple program that subscribes to X's keyboard layout
change event and outputs the keyboard layout everytime
it changes.

## install

arch users can use the AUR package: `paru -S xkblayout-subscribe-git`

install: `make; sudo make install`

remove: `sudo make uninstall`

## example usage

this command notifies current keyboard layout upon
keyboard layout change:

```sh
xkblayout-subscribe | xargs -L1 sh -c '
    case $0 in
        0) lang=en ;;
        1) lang=fa ;;
    esac
    notify-send "$lang"
'
```

or you can install and use `xkblayout-state`:

```sh
xkblayout-subscribe |
    xargs -L1 sh -c 'notify-send $(xkblayout-state print %s)'
```
