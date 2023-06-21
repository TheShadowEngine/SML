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

+ (instancetype)matrixOfRows:(int)m
                     columns:(int)n
            valueInDiagonal:(double)diagonal
                       value:(double)val;

+ (instancetype)matrixOfRows:(int)m
                     columns:(int)n
            valuesInDiagonal:(double *)diagonal
                       value:(double)val;

+ (instancetype)matrixFromArray:(double *)arr rows:(int)m columns:(int)n;

+ (instancetype)matrixFromArray:(double *)arr rows:(int)m columns:(int)n mode:(refMode)mode;

+ (instancetype)matrixFromNSArray:(NSArray *)arr rows:(int)m columns:(int)n;

+ (instancetype)matrixFromMatrix:(Matrix *)other;

+ (instancetype)identityOfRows:(int)m columns:(int)n;

- (double)valueAtRow:(int)row column:(int)column;

- (double)i:(int)i j:(int)j;

- (void)setValue:(double)value row:(int)row column:(int)column;

- (void)i:(int)i j:(int)j set:(double)value;

- (void)i:(int)i j:(int)j increment:(double)value;

- (void)incrementAll:(double)value;

- (Matrix *)matrixByAdding:(Matrix *)addend;

- (Matrix *)matrixBySubtracting:(Matrix *)subtrahend;

- (Matrix *)matrixByMultiplyingWithRight:(Matrix *)mt;

- (Matrix *)matrixByMultiplyingWithRight:(Matrix *)mt AndTransposing:(bool)trans;

- (Matrix *)matrixByMultiplyingWithRight:(Matrix *)mt AndAdding:(Matrix *)ma;

- (Matrix *)matrixByMultiplyingWithRight:(Matrix *)mt AndFactor:(double)sf;

- (Matrix *)matrixByTransposingAndMultiplyingWithRight:(Matrix *)mt;

- (Matrix *)matrixByTransposingAndMultiplyingWithLeft:(Matrix *)mt;

- (Matrix *)matrixByMultiplyingWithScalar:(double)ms;

- (Matrix *)matrixByMultiplyingWithScalar:(double)ms AndAdding:(Matrix *)addend;

- (Matrix *)matrixByNegating;

- (Matrix *)matrixBySquaring;

- (Matrix *)matrixByAbsolute;

- (Matrix *)matrixByTransposing;

- (Matrix *)matrixByElementWiseMultiplyWith:(Matrix *)mt;

- (Matrix *)matrixByElementWisDivideBy:(Matrix *)mt;

- (void)add:(Matrix *)addend;

- (void)subtract:(Matrix *)subtrahend;

- (void)multiplyWithScalar:(double)ms;

- (void)negate;

- (void)square;

- (void)absolute;

- (void)elementWiseMultiply:(Matrix *)mt;

- (void)elementWiseDivide:(Matrix *)mt;

- (void)setDiagonalTo:(double)value;

- (double)trace;

- (double)dotWith:(Matrix *)other;

- (Matrix *)matrixByUnitizing;

- (BOOL)isEqualToMatrix:(Matrix *)aMatrix tolerance:(double)tolerance;

@property (readonly) double *array;

@property (readonly) double *arrayCopy;

@property (readonly) NSArray *numberArray;

@property (readonly) Matrix *diagonal;

@property (readonly) int rows;

@property (readonly) int columns;

@property (readonly) NSUInteger count;

@property (readonly) double sum;

@property (readonly) double product;

@property (readonly) double min;

@property (readonly) double max;

@property (readonly) BOOL isSquareMatrix;

@end
