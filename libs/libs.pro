TEMPLATE = subdirs

SUBDIRS = \
    clipper \
    delaunay-triangulation \
    fontobene \
    hoedown \
    googletest \
    librepcb \
    muparser \
    optional \
    parseagle \
    sexpresso \

librepcb.depends = \
    clipper \
    delaunay-triangulation \
    fontobene \
    muparser \
    optional \
    parseagle \
    hoedown \
    sexpresso \

!contains(UNBUNDLE, quazip) {
    SUBDIRS += quazip
    librepcb.depends += quazip
}
