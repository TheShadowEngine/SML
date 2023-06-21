//
//  HaltonInterface.h
//  SML
//
//  Created by krisna pranav on 21/06/23.
//

#import <Foundation/Foundation.h>

@class Matrix;

@interface HaltonInterface : NSObject

+ (Matrix *)sampleWithDimension:(int)dimension count:(int)count;

@end
