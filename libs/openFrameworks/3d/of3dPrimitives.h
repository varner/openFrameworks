//
//  of3dPrimitives.h
//  openFrameworksLib
//
//  Created by Nick Hardeman on 9/14/12.
//
//
#pragma once

#include "ofVboMesh.h"
#include "ofRectangle.h"
#include "ofNode.h"
#include "ofTexture.h"
#include <map>


class of3dPrimitive : public ofNode {
public:
    of3dPrimitive();
    virtual ~of3dPrimitive();
    
    of3dPrimitive(const of3dPrimitive & mom);
    of3dPrimitive & operator=(const of3dPrimitive & mom);

    /// \brief Creates tex coordinates from texture (does not store texture!)
    /// 
    /// Will create normalized tex coords if non-arb
    /// Defaults of index 0
    ///
    /// \param u1 EDIT ME
    /// \param v1 EDIT ME
    /// \param u2 EDIT ME
    /// \param v2 EDIT ME
    void mapTexCoords( float u1, float v1, float u2, float v2 );
    //void setTexCoords( int meshindex, float u1, float v1, float u2, float v2 );
    // does not store texture. Creates tex coords from texture, if texture is
    // non-arb, then it will create normalized tex coords //
    // defaults to index 0 
    
    void mapTexCoordsFromTexture( ofTexture& inTexture );
    
    
    ofMesh* getMeshPtr();
    ofMesh& getMesh();
    
    ofVec4f* getTexCoordsPtr();
    ofVec4f& getTexCoords();
    
    bool hasScaling();
    bool hasNormalsEnabled();
    
    void enableNormals();
    void enableTextures();
    void enableColors();
    
    void disableNormals();
    void disableTextures();
    void disableColors();
    
    void removeMesh( int index );
    void removeTexture( int index );
    void clear();
    
    void drawVertices();
    void drawWireframe();
    void drawFaces();
    void draw();
    void draw(ofPolyRenderMode renderType);
    void drawNormals( float length, bool bFaceNormals=false );
    void drawAxes(float a_size);
    
    void setUseVbo(bool useVbo);
    bool isUsingVbo();
protected:
    
    // useful when creating a new model, since it uses normalized tex coords //
    void normalizeAndApplySavedTexCoords();
    
    ofVec4f texCoords;
    bool usingVbo;
    ofPtr<ofMesh>  mesh;
    ofMesh normalsMesh;
    
    vector<ofIndexType> getIndices( int startIndex, int endIndex );
    
};

class ofPlanePrimitive : public of3dPrimitive {
public:

    ofPlanePrimitive();
    ofPlanePrimitive( float width, float height, int columns, int rows, ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );
    ~ofPlanePrimitive();
    
    /// \brief Verbose set method for plane.
    ///
    /// \param width Width of the plane
    /// \param height Height of the plane
    /// \param columns Number of columns for faces
    /// \param rows Number of rows for faces
    /// \param mode Optional, defaults to triangle strip
    void set(float width, float height, int columns, int rows, ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );
    
    /// \brief Set just the width and height
    /// \param width Width of the plane
    /// \param height Height of the plane
    void set( float width, float height );
    
    void resizeToTexture( ofTexture& inTexture, float scale=1.f );
    
    /// \brief Set just the width
    /// \param width Width of the plane
    void setWidth( float width );

    /// \brief Set just the height
    /// \param width Height of the plane
    void setHeight( float height );
    
    /// \brief Set just column amount
    /// \param columns Number of columns
    void setColumns( int columns );
    
    /// \brief Set just row amount
    /// \param rows Number of rows
    void setRows( int rows );
    
    /// \brief Set both rows & columns
    /// \param columns Number of columns for faces
    /// \param rows Number of rows for faces
    void setResolution( int columns, int rows );
    
    /// \brief Set mode of plane
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Get the amount of columns
    /// \returns An int with the total amount of columns
    int getNumColumns();
    
    /// \brief Get the amount of rows
    /// \returns An int with the total amount of rows
    int getNumRows();
    
    /// \brief Gets the amount of rows and columns.
    /// \returns A 2D vector where (x = columns) and (y = rows)
    ofVec2f getResolution();
    
    /// \brief Gets width of the plane
    /// \returns A float of the width of the plane
    float getWidth();
    
    /// \brief Gets height of the plane
    /// \returns A float of the height of the plane
    float getHeight();
    
protected:
    float width;
    float height;
    ofVec2f resolution;
};

class ofSpherePrimitive : public of3dPrimitive {
public:
    ofSpherePrimitive();
    ofSpherePrimitive( float radius, int res, ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );
    ~ofSpherePrimitive();
    
    /// \brief Verbose set method for sphere.
    /// 
    /// \param radius The radius of the sphere
    /// \param res The amount of latitude divides along the sphere.
    /// \param mode The ofPrimitiveMode being used
    void set( float radius, int resolution, ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );
    
    /// \brief set the resolution of the sphere.
    /// \param res The amount of latitude divides along the sphere.
    void setResolution( int res );
    
    /// \brief Set radius of sphere.
    /// \param radius The radius of the sphere
    void setRadius(float radius);
    
    /// \brief Set mode of sphere
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Get radius value
    /// \param radius A float, radius of the sphere
    float getRadius();
    
    /// \brief Get resolution value
    /// \returns An int of the amount of latitude divides along the sphere.
    int getResolution();
    
protected:
    float radius;
    int resolution;
};

class ofIcoSpherePrimitive : public of3dPrimitive {
public:
    ofIcoSpherePrimitive();
    ofIcoSpherePrimitive( float radius, int iterations );
    ~ofIcoSpherePrimitive();
    
    /// \brief Set radius and resolution of the IcoSphere
    /// \param radius
    /// \param res
    void set( float radius, int res );
    
    /// \brief Set the resolution of the IcoSphere
    /// \param iterations
    void setResolution( int iterations );
    
    /// \brief Set the radius of the IcoSphere
    /// \param radius   
    void setRadius( float radius );
    
    /// \brief Set the mode of the IcoSphere
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    // \brief Set the mode 
    float getRadius();
    int getResolution();
    
protected:
    float radius;
    int resolution;
};

class ofCylinderPrimitive : public of3dPrimitive {
public:
    ofCylinderPrimitive();
    ofCylinderPrimitive( float radius, float height, int radiusSegments, int heightSegments, int capSegments=2, bool bCapped = true,ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );
    ~ofCylinderPrimitive();
    
    /// \brief Verbose set method for cylinder
    ///
    /// \param radius Float of the radius of the cylinder
    /// \param height Float of the height of the cylinder
    /// \param radiusSegments Amount of faces subdividing the circle face (think longitude on a globe)
    /// \param heightSegments Amount of vertical faces (think latitude on a globe)
    /// \param capSegments Circular plane creates triangles, you're subdividing those triangles. Optional.
    /// \param bCapped If false cylinder has no endcaps (like a pipe), else normal closed cylinder. Optional.
    /// \param mode The ofPrimitiveMode being used
    void set( float radius, float height, int radiusSegments, int heightSegments, int capSegments=2, bool bCapped=true,ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );

    /// \brief Set just the radius, height, and optionally the endcaps.
    /// \param radius Float of the radius of the cylinder
    /// \param height Float of the height of the cylinder
    /// \param bCapped If false cylinder has no endcaps (like a pipe), else normal closed cylinder. Optional.
    void set( float radius, float height, bool bCapped=true );
   
    /// \brief Set just the radius
    /// \param radius Float of the radius of the cylinder
    void setRadius( float radius );
    
    /// \brief Set just the height
    /// \param height Float of the height of the cylinder
    void setHeight( float height );
    
    /// \brief Set the endcaps' state
    /// \param bCapped If false cylinder has no endcaps (like a pipe), else normal closed cylinder.
    void setCapped( bool bCapped );
    
    /// \brief Set just the radius resolution
    /// \param radiusRes Amount of faces subdividing the circle face (think longitude on a globe)
    void setResolutionRadius( int radiusRes );
    
    /// \brief Set just the radius resolution
    /// \param heightRes Amount of vertical faces (think latitude on a globe)
    void setResolutionHeight( int heightRes );
    
    /// \brief Set just the resolution cap
    /// \param capRes Circular plane creates triangles, you're subdividing those triangles. Optional.
    void setResolutionCap( int capRes );
    
    /// \brief Set ALLL the resolution
    /// \param radiusSegments Amount of faces subdividing the circle face (think longitude on a globe)
    /// \param heightSegments Amount of vertical faces (think latitude on a globe)
    /// \param capSegments Circular plane creates triangles, you're subdividing those triangles. Optional.
    void setResolution( int radiusSegments, int heightSegments, int capSegments=2 );
    
    /// \brief Set mode of cylinder
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Sets the color of the top cap
    /// \param ofColor
    void setTopCapColor( ofColor color );
    
    /// \brief Sets the color of the cylinder
    /// \param ofColor
    void setCylinderColor( ofColor color );
    
    /// \brief Sets the color of the bottom cap
    /// \param ofColor
    void setBottomCapColor( ofColor color );
    
    vector<ofIndexType> getTopCapIndices();
    ofMesh getTopCapMesh();
    vector<ofIndexType> getCylinderIndices();
    ofMesh getCylinderMesh();
    vector<ofIndexType> getBottomCapIndices();
    ofMesh getBottomCapMesh();
    
    int getResolutionRadius();
    int getResolutionHeight();
    int getResolutionCap();
    ofVec3f getResolution();
    
    float getHeight();
    float getRadius();
    bool getCapped();
    
protected:
    float radius;
    float height;
    bool bCapped;
    int strides[3][2];
    int vertices[3][2];
    ofVec3f resolution;
};

class ofConePrimitive : public of3dPrimitive {
public:
    
    ofConePrimitive();
    ofConePrimitive( float radius, float height, int radiusSegments, int heightSegments, int capSegments=2, ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );
    ~ofConePrimitive();
    
    void set( float radius, float height, int radiusSegments, int heightSegments, int capSegments=2, ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );
    void set( float radius, float height );
    void setResolutionRadius( int radiusRes );
    void setResolutionHeight( int heightRes );
    void setResolutionCap( int capRes );
    void setResolution( int radiusRes, int heightRes, int capRes );
    
    void setMode( ofPrimitiveMode mode );
    void setRadius( float radius );
    void setHeight( float height );
    
    void setTopColor( ofColor color );
    void setCapColor( ofColor color );
    
    vector<ofIndexType> getConeIndices();
    ofMesh getConeMesh();
    vector<ofIndexType> getCapIndices();
    ofMesh getCapMesh();
    
    int getResolutionRadius();
    int getResolutionHeight();
    int getResolutionCap();
    ofVec3f getResolution();
    
    float getRadius();
    float getHeight();
    
protected:
    float radius;
    float height;
    
    ofVec3f resolution;
    
    int strides[2][2];
    int vertices[2][2];
};

class ofBoxPrimitive : public of3dPrimitive {
public:

    enum BoxSides {
        SIDE_FRONT,
        SIDE_RIGHT,
        SIDE_LEFT,
        SIDE_BACK,
        SIDE_TOP,
        SIDE_BOTTOM,
        SIDES_TOTAL
    };
    ofBoxPrimitive();
    ofBoxPrimitive( float width, float height, float depth, int resWidth=2, int resHeight=2, int resDepth=2 );
    ~ofBoxPrimitive();
    
    void set( float width, float height, float depth, int resWidth, int resHeight, int resDepth);
    void set( float width, float height, float depth );
    void set( float size ); // all sides the same dimensions //
    
    void setWidth( float a_width );
    void setHeight( float a_height );
    void setDepth( float a_depth );
    
    void resizeToTexture( ofTexture& inTexture );
    
    vector<ofIndexType> getSideIndices( int sideIndex );
    ofMesh getSideMesh( int sideIndex );
    
    void setResolution( int res ); // same resolution for all sides //
    void setResolutionWidth( int widthRes );
    void setResolutionHeight( int heightRes );
    void setResolutionDepth( int depthRes );
    void setResolution( int resWidth, int resHeight, int resDepth );
    
    void setMode( ofPrimitiveMode mode );
    void setSideColor( int sideIndex, ofColor color );
    
    int getResolutionWidth();
    int getResolutionHeight();
    int getResolutionDepth();
    ofVec3f getResolution();
    
    float getWidth();
    float getHeight();
    float getDepth();
    ofVec3f getSize() const;
protected:
    ofVec3f size;
    ofVec3f resolution;
    // indices strides for faces //
    int strides[6][2];
    int vertices[6][2];

};
















