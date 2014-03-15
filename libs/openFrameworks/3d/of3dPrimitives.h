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
    ///
    /// \param width Width of the plane
    /// \param height Height of the plane
    void set( float width, float height );
    
    /// \brief 
    ///
    /// \param inTexture ________
    /// \param scale ________ Optional.
    void resizeToTexture( ofTexture& inTexture, float scale=1.f );
    
    /// \brief Set just the width
    ///
    /// \param width Width of the plane
    void setWidth( float width );

    /// \brief Set just the height
    ///
    /// \param width Height of the plane
    void setHeight( float height );
    
    /// \brief Set just column amount
    ///
    /// \param columns Number of columns
    void setColumns( int columns );
    
    /// \brief Set just row amount
    ///
    /// \param rows Number of rows
    void setRows( int rows );
    
    /// \brief Set both rows & columns
    ///
    /// \param columns Number of columns for faces
    /// \param rows Number of rows for faces
    void setResolution( int columns, int rows );
    
    /// \brief Set mode of plane
    ///
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Get the amount of columns
    ///
    /// \returns An int with the total amount of columns
    int getNumColumns();
    
    /// \brief Get the amount of rows
    ///
    /// \returns An int with the total amount of rows
    int getNumRows();
    
    /// \brief Gets the amount of rows and columns.
    ///
    /// \returns A 2D vector where (x = columns) and (y = rows)
    ofVec2f getResolution();
    
    /// \brief Gets width of the plane
    ///
    /// \returns A float of the width of the plane
    float getWidth();
    
    /// \brief Gets height of the plane
    ///
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
    ///
    /// \param res The amount of latitude divides along the sphere.
    void setResolution( int res );
    
    /// \brief Set radius of sphere.
    ///
    /// \param radius The radius of the sphere
    void setRadius(float radius);
    
    /// \brief Set mode of sphere
    ///
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Get radius value
    ///
    /// \param radius A float, radius of the sphere
    float getRadius();
    
    /// \brief Get resolution value
    ///
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
    ///
    /// \param radius Radius of the sphere, float
    /// \param res Number of faces, int
    void set( float radius, int res );
    
    /// \brief Set the resolution of the IcoSphere
    ///
    /// \param iterations
    void setResolution( int iterations );
    
    /// \brief Set the radius of the IcoSphere
    ///
    /// \param radius The radius of the IcoSphere, float 
    void setRadius( float radius );
    
    /// \brief Set the mode of the IcoSphere
    ///
    /// \warning ofIcoSpherePrimitive only works with OF_PRIMITIVE_TRIANGLES
    ///
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Get the radius
    ///
    /// \returns The radius of the IcoSphere, float
    float getRadius();
    
    /// \brief Gets the resolution of the IcoSphere
    ///
    /// \returns The resolution of the IcoSphere, int
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
    ///
    /// \param radius Float of the radius of the cylinder
    /// \param height Float of the height of the cylinder
    /// \param bCapped If false cylinder has no endcaps (like a pipe), else normal closed cylinder. Optional.
    void set( float radius, float height, bool bCapped=true );
   
    /// \brief Set just the radius
    ///
    /// \param radius Float of the radius of the cylinder
    void setRadius( float radius );
    
    /// \brief Set just the height
    ///
    /// \param height Float of the height of the cylinder
    void setHeight( float height );
    
    /// \brief Set the endcaps' state
    ///
    /// \param bCapped If false cylinder has no endcaps (like a pipe), else normal closed cylinder.
    void setCapped( bool bCapped );
    
    /// \brief Set just the radius resolution
    ///
    /// \param radiusRes Amount of faces subdividing the circle face (think longitude on a globe)
    void setResolutionRadius( int radiusRes );
    
    /// \brief Set just the radius resolution
    ///
    /// \param heightRes Amount of vertical faces (think latitude on a globe)
    void setResolutionHeight( int heightRes );
    
    /// \brief Set just the resolution cap
    ///
    /// \param capRes Circular plane creates triangles, you're subdividing those triangles. Optional.
    void setResolutionCap( int capRes );
    
    /// \brief Set ALLL the resolution
    ///
    /// \param radiusSegments Amount of faces subdividing the circle face (think longitude on a globe)
    /// \param heightSegments Amount of vertical faces (think latitude on a globe)
    /// \param capSegments Circular plane creates triangles, you're subdividing those triangles. Optional.
    void setResolution( int radiusSegments, int heightSegments, int capSegments=2 );
    
    /// \brief Set mode of cylinder
    ///
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Sets the color of the top cap
    ///
    /// \param color The desired color
    void setTopCapColor( ofColor color );
    
    /// \brief Sets the color of the cylinder
    ///
    /// \param color The desired color
    void setCylinderColor( ofColor color );
    
    /// \brief Sets the color of the bottom cap
    ///
    /// \param color The desired color
    void setBottomCapColor( ofColor color );
    
    /// \brief Gets a list of face indices for the top cap
    ///
    /// \warning Mode must be in triangle strip mode
    ///
    /// \returns A list of face indicdes for the top cap
    vector<ofIndexType> getTopCapIndices();
    
    /// \brief Gets a the mesh of the top cap (NOT entire cylinder)
    ///
    /// \returns A ofMesh of the top cap (NOT entire cylinder)
    ofMesh getTopCapMesh();
    
    /// \brief Gets a list of face indices for the cylinder
    ///
    /// \warning Mode must be in triangle strip mode
    ///
    /// \returns A list of face indices for the cylinder
    vector<ofIndexType> getCylinderIndices();
    
    /// \brief Gets the mesh of the cylinder (including caps)
    ///
    /// \returns The mesh of the entire cylinder
    ofMesh getCylinderMesh();
    
    /// \brief Gets a list of face indices for the bottom cap
    ///
    /// \warning Mode must be in triangle strip mode
    ///
    /// \returns A list of the face indices for the bottom cap
    vector<ofIndexType> getBottomCapIndices();
    
    /// \brief Gets of the mesh of the bottom cap (NOT entire cylinder)
    ///
    /// \returns A ofMesh of the bottom cap (NOT entire cylinder)
    ofMesh getBottomCapMesh();
    
    /// \brief Gets the resolution of the cylinder's radius
    ///
    /// \returns The resolution of the cylinder's radius 
    int getResolutionRadius();
    
    /// \brief Gets the resolution of the cylinder's height
    ///
    /// \returns The amount of subdivisions running parallel to the caps (resolution of the cylinder height)
    int getResolutionHeight();
    
    /// \brief Gets the resolution of the cap
    ///
    /// \returns The amount of segments for the cap
    int getResolutionCap();
    
    /// \brief Gets the resolution of the cylinder
    ///
    /// \returns A 3D vector with the format (radiusSegments, heightSegments, capSegments)
    ofVec3f getResolution();
    
    /// \brief Gets the height of the cylinder
    ///
    /// \returns The height of the cylinder
    float getHeight();
    
    /// \brief Gets the radius of the cylinder
    ///
    /// \returns The radius of the cylinder
    float getRadius();
    
    /// \brief 
    ///
    /// \returns 
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
    
    /// \brief Verbose set method for cone
    ///
    /// \param radius The radius of the cone, float
    /// \param height The height of the cone, float
    /// \param radiusSegments Amount of faces subdividing the circle face (think longitude on a globe)
    /// \param heightSegments Amount of vertical faces (think latitude on a globe)
    /// \param capSegments Circular plane creates triangles, you're subdividing those triangles. Optional.
    /// \param mode The ofPrimitiveMode being used
    void set( float radius, float height, int radiusSegments, int heightSegments, int capSegments=2, ofPrimitiveMode mode=OF_PRIMITIVE_TRIANGLE_STRIP );
    
    /// \brief Set just the radius and height of cone
    ///
    /// \param radius The radius of the cone, float
    /// \param height The height of the cone, float
    void set( float radius, float height );
    
    /// \brief Set just the resolution the cone radius (as opposed to the cap)
    /// 
    /// \param radiusRes The amount of segments for the radius
    void setResolutionRadius( int radiusRes );
    
    /// \brief Set just the resolution of the cone height (as opposed to the cap)
    /// 
    /// \param heightRes The amount of segments for the height
    void setResolutionHeight( int heightRes );
    
    /// \brief Set just the resolution of the cap (as opposed to the cone)
    ///
    /// \param capRes The amount of segments for the cap
    void setResolutionCap( int capRes );
    
    /// \brief Set the resolution for the cone
    ///
    /// \param radiusRes The amount of segments for the radius
    /// \param heightRes The amount of segments for the height
    /// \param capRes The amount of segments for the cap
    void setResolution( int radiusRes, int heightRes, int capRes );
    
    /// \brief Set just the mode of the cone/cap.
    ///
    /// \param mode The ofPrimitiveMode being used
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Set just the radius of the cone
    ///
    /// \param radius The radius of the cone, float
    void setRadius( float radius );
    
    /// \brief Set the height of the cone
    ///
    /// \param height The height of the cone, float
    void setHeight( float height );
    
    /// \brief Set the color of the cone (discluding the cap)
    ///
    /// \param color The desired color 
    void setTopColor( ofColor color );
    
    /// \brief Set the color of the cap (not the rest of the cone)
    ///
    /// \param color The desired color
    void setCapColor( ofColor color );
    
    vector<ofIndexType> getConeIndices();
    ofMesh getConeMesh();
    
    vector<ofIndexType> getCapIndices();
    
    /// \brief Returns an ofMesh made up of the cap (NOT including the cone)
    /// \returns an ofMesh of the cap (NOT including the cone)
    ofMesh getCapMesh();
    
    /// \brief Gets the resolution for the radius
    ///
    /// \returns The amount of segments for the radius
    int getResolutionRadius();
    
    /// \brief Gets the resolution for the height
    ///
    /// \returns The amount of segments for the height
    int getResolutionHeight();
    
    /// \brief Gets the radius of the cap (rather than the cone)
    ///
    /// \returns Segments for the cap
    int getResolutionCap();
    
    /// \brief Get resolution of the cone (rather than the cap)
    ///
    /// \returns A vector with the segments for the cone in the format (radiusSegments, heightSegments, capSegments)
    ofVec3f getResolution();
    
    /// \brief Gest the radius of the cone
    ///
    /// \returns The radius of the cone
    float getRadius();
    
    /// \brief Gets the height of the cone
    ///
    /// \returns The height of the cone
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
    
    /// \brief Verbose set method for box
    ///
    /// \param width Width of the box, float
    /// \param height Height of the box, float
    /// \param depth Depth of the box, float
    /// \param resWidth Amount of subdivisions of the faces width-wise
    /// \param resHeight Amount of subdivisions of the faces height-wise
    /// \param resDepth Amount of subdivisions of the fasces depth-wise
    void set( float width, float height, float depth, int resWidth, int resHeight, int resDepth);
    
    /// \brief Set the dimensions of the box
    ///
    /// \param width Width of the box, float
    /// \param height Height of the box, float
    /// \param depth Depth of the box, float
    void set( float width, float height, float depth );
    
    /// \brief Set method to create a cube (All sides are the same length)
    ///
    /// \param size Length of any given side of the box, float
    void set( float size );
    
    /// \brief Set just the width of the box
    ///
    /// \param a_width Desired width of the box, float
    void setWidth( float a_width );
    
    /// \brief Set just the height of the box
    ///
    /// \param a_height Desired height of the box, float
    void setHeight( float a_height );
    
    /// \brief Set just the depth of the box
    ///
    /// \param a_depth Desired depth of the box, float
    void setDepth( float a_depth );
    
    void resizeToTexture( ofTexture& inTexture );
    
    vector<ofIndexType> getSideIndices( int sideIndex );
    
    /// \brief Gets the mesh of the given side
    ///
    /// \param sideIndex The index of the desired side
    ///
    /// \returns returns a mesh of the given side
    ofMesh getSideMesh( int sideIndex );
    
    /// \brief Set the same resolution for all sides
    ///
    /// \param res Amount of subdivisions of the faces
    void setResolution( int res );
    
    /// \brief Set just the resolution width
    ///
    /// \param resWidth Amount of subdivisions of the faces width-wise
    void setResolutionWidth( int widthRes );

    /// \brief Set just the resolution height
    ///
    /// \param resHeight Amount of subdivisions of the faces height-wise
    void setResolutionHeight( int heightRes );
    
    /// \brief Set just the resolution depth
    /// \param resDepth Amount of subdivisions of the fasces depth-wise
    void setResolutionDepth( int depthRes );

    /// \brief Set the resolution for all
    ///
    /// \param resWidth Amount of subdivisions of the faces width-wise
    /// \param resHeight Amount of subdivisions of the faces height-wise
    /// \param resDepth Amount of subdivisions of the fasces depth-wise
    void setResolution( int resWidth, int resHeight, int resDepth );
 
    /// \brief Set the ofPrimitiveMode
    ///
    /// \param mode The ofPrimitiveMode being used   
    void setMode( ofPrimitiveMode mode );
    
    /// \brief Sets the color for the given side
    ///
    /// \param sideIndex The index number for the desired side
    /// \param color The desired color
    void setSideColor( int sideIndex, ofColor color );
    
    /// \brief Gets the resolution for the width
    ///
    /// \returns Amount of subdivisions width-wise, int
    int getResolutionWidth();
    
    /// \brief Gets the resolution for the height
    ///
    /// \returns Amount of subdivisions height-wise, int
    int getResolutionHeight();
    
    /// \brief Gets the resolution for the depth
    ///
    /// \returns Amount of subdivisions depth-wise, int
    int getResolutionDepth();
    
    /// \brief Gets the resolution of the box
    ///
    /// \returns A 3D Vector of the resolution with the format (width, height, depth)
    ofVec3f getResolution();
    
    /// \brief Gets the width of the box
    ///
    /// \returns The width of the box, float
    float getWidth();
    
    /// \brief Gets the height of the box
    ///
    /// \returns The width of the box, float
    float getHeight();
    
    /// \brief Gets the depth of the box
    ///
    /// \returns The depth of the box, float
    float getDepth();
    
    /// \brief Returns the width, height and depth of box as a 3D vector.
    ///
    /// \returns Returns a 3d vector with dimension info (format -> (width, height, depth))
    ofVec3f getSize() const;
    
protected:
    ofVec3f size;
    ofVec3f resolution;
    // indices strides for faces //
    int strides[6][2];
    int vertices[6][2];

};
















