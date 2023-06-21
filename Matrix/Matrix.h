//
//  Matrix.h
//  SML
//
//  Created by krisna pranav on 21/06/23.
//

typedef enum refMode {
    SWeak, SStrong, SCopy
} refMode;

#import <Foundation/Foundation.h>
#import <Accelerate/Accelerate.h>

@interface Matrix : NSObject <NSCoding, NSCopying> {
    @public double *matrix;
    @public int rows;
    @public int columns;
    @private BOOL freeData;
}


+(instancetype)matrixOfRows:(int)m columns:(int)n;

+(instancetype)matrixLike:(Matrix *)other;

+(instancetype)onesLike:(Matrix *)other;

+(instancetype)matrixOfRows:(int)m columns:(int)n value:(double)val;
