/**
 * C++ Port of the TurboReg ImageJ Plugin
 * Original code by Philippe Thevenaz (see below)
 * Porting by Gregor Lichtner
 */


/*====================================================================
| Philippe Thevenaz
| EPFL/STI/IMT/LIB/BM.4.137
| Station 17
| CH-1015 Lausanne VD
| Switzerland
|
| phone (CET): +41(21)693.51.61
| fax: +41(21)693.37.01
| RFC-822: philippe.thevenaz@epfl.ch
| X-400: /C=ch/A=400net/P=switch/O=epfl/S=thevenaz/G=philippe/
| URL: http://bigwww.epfl.ch/
\===================================================================*/

/*====================================================================
| This work is based on the following paper:
|
| P. Thevenaz, U.E. Ruttimann, M. Unser
| A Pyramid Approach to Subpixel Registration Based on Intensity
| IEEE Transactions on Image Processing
| vol. 7, no. 1, pp. 27-41, January 1998.
|
| This paper is available on-line at
| http://bigwww.epfl.ch/publications/thevenaz9801.html
|
| Other relevant on-line publications are available at
| http://bigwww.epfl.ch/publications/
\===================================================================*/

/*====================================================================
| Additional help available at http://bigwww.epfl.ch/thevenaz/turboreg/
|
| You'll be free to use this software for research purposes, but you
| should not redistribute it without our consent. In addition, we expect
| you to include a citation or acknowledgment whenever you present or
| publish results that are based on it.
\===================================================================*/

#include "TurboReg.h"
#include "TurboRegImage.h"
#include <cmath>
#include "matrix.h"

#ifndef TURBOREGPOINTHANDLER_H_
#define TURBOREGPOINTHANDLER_H_

class TurboRegPointHandler
{ /* class TurboRegPointHandler */
public:

    TurboRegPointHandler (
        TurboRegImage &img,
		Transformation transformation
    );

    TurboRegPointHandler (
    	matrix<double> &precisionPoint
    );

    matrix<double> &getPoints();

    void setPoints (
        matrix<double> &precisionPoint
    );

    void setPointsByTransformation(
		int width,
		int height,
    	Transformation transformation
	);

private:
    /*********************************************************************
     The number of points we are willing to deal with is at most
    <code>4</code>.
    @see TurboRegDialog#transformation
    ********************************************************************/
    int NUM_POINTS = 4;

    /*********************************************************************
     The golden ratio mathematical constant determines where to put the
    initial landmarks.
    ********************************************************************/
    double GOLDEN_RATIO = 0.5 * (sqrt(5.0) - 1.0);


    matrix<double> precisionPoint; // = new double[NUM_POINTS * 2];
};


#endif
