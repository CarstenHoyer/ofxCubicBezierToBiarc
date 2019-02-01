# Bezier curve approximation algorithm with biarcs

## Synopsis
This is more or less a one-to-one implementation of https://github.com/domoszlai/bezier2biarc for openFrameworks.

## Installation
You can install this as any other openFrameworks addon.

## Implementation
The algorithm is explained by Domoszlai in this blog post: http://dlacko.org/blog/2016/10/19/approximating-bezier-curves-by-biarcs/.

## Usage
Create a number of cubic bezier paths in openFrameworks.

Convert them to BiArcs by calling ofxCubicBezierToBiArc::ApproxCubicBezier().

## Limitations
* The code only works in 2D space.
* It will not check if the input actually is cubic beziers, and it has not been tested on other inputs.

## Screenshots

### Original paths
![Original paths](./screenshots/original.png?raw=true)

### BiArc paths
![BiArc paths](./screenshots/biarcs.png?raw=true)

### Overlay of original and BiArcs.(here the BiArcs are translated by ofPoint(1,1) to make them more visible)
![Overlay](./screenshots/overlay.png?raw=true)
