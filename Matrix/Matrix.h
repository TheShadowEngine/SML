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

+(instancetype)matrixOfRows:(int)m columns:(int)n valueInDiagonal:(double)diagonal value:(double)val;

+(instancetype)matrixOfRows:(int)m columns:(int)m valuesInDiagonal:(double *)diagonal value:(double)val;

+(instancetype)matrixFromArray:(double *)arr rows:(int)m columns:(int)n;

+(instancetype)matrixFromArray:(double *)arr rows:(int)m columns:(int)n mode:(refMode)mode;

+(instancetype)matrixFromNSArray:(NSArray *)arr rows:(int)m columns:(int)n;

+(instancetype)matrixFromMatrix:(Matrix *)other;

+(instancetype)identityOfRows:(int)m columns:(int)n;

-(double)valueAtRow:(int)row column:(int) column;

-(double)i:(int)i j:(int)j;

-(void)setValue:(double)value row:(int)row column:(int)column;

