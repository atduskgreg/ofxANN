## ofxANN

This is an addon for [OpenFrameworks](http://openframeworks.cc) that wraps [libANN](http://www.cs.umd.edu/~mount/ANN/), a library for Approximate Nearest Neighbor search. It is minimal and doesn't wrap all of ANN's extensive functionality. It currently only provides methods for loading ofVec3fs into ANN and getting the neighbors (this is all you need in most cases). Note: by default, ofxANN sets the allowed error margin to 0 making this exact nearest neighbor search rather than approximate. If you're searching for a lot of neighbors or over a truly titanic data set, you can set the allowed error margin to something higher with setEps().

There's an example to demonstrate API usage.

_NOTE: ofxANN includes a 32-bit build of libANN that was created on Mac OSX for compatibility with OF. ANN is relatively easy to build if you follow the instructions for your system on their site. I welcome contributions that add support for other systems._