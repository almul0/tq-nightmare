# ======================= ofxCMake Vers. 0.1 =============
#  PUT THIS FILE INTO YOUR OPENFRAMEWORKS PROJECT FOLDER

# ========================================================
# ===================== CMake Settings ===================
# ========================================================
cmake_minimum_required( VERSION 3.3 )
project( tq-nightmare )

# ========================================================
# ===================== User Settings ====================
# ========================================================
# ---------------------- App name  -----------------------
set( APP_NAME   tq-nightmare )

# ------------------------ OF Path -----------------------
# --- If outside the OF structure, set an absolute OF path
set( OF_DIRECTORY_BY_USER "/opt/openframeworks" )

# --------------------- Source Files ---------------------
set( ${APP_NAME}_SOURCE_FILES
        src/main.cpp
        src/ofApp.cpp
        src/ofxStage17.cpp
        src/ofxStage.cpp
        src/ofxStage6.cpp
        src/ofxStage19.cpp
        src/ofxStage3.cpp
        src/ofxStage15.cpp
        src/ofxMenu.cpp
        src/ofxStage13.cpp
        src/ofxStage9.cpp
        src/ofxStage12.cpp
        src/ofxStage4.cpp
        src/ofxStage8.cpp
        src/ofxStage2.cpp
        src/ofxStage1.cpp
        src/ofxStage10.cpp
        src/ofxStage11.cpp
        src/ofxStage14.cpp
        src/ofxStage5.cpp
        src/ofxStage7.cpp
        src/ofxStage16.cpp
        src/ofxStage18.cpp)


# ------------------------ AddOns  -----------------------
set( OFX_ADDONS_ACTIVE
        # ofxWiiMouse
        ofxStreamingSender
        #        ofxXmlSettings
        #        ofxOsc
        #        ofxGui
        #        ofxNetwork
        #        ofxVectorGraphics
        #        ofxThreadedImageLoader
        #        ofxAssimpModelLoader
        #        ofxKinect
                ofxOpenCv
        #        ofxSvg
        #        ofxEmscripten (untested)
                ofxPSMove
                ofxStreamingSender
                )

# =========================================================================
# ============================== OpenFrameworks ===========================
# =========================================================================
include( ${OF_DIRECTORY_BY_USER}/addons/ofxCMake/modules/main.cmake )
# =========================================================================

