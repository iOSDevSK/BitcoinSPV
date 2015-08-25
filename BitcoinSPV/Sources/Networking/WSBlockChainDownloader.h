//
//  WSBlockChainDownloader.h
//  BitcoinSPV
//
//  Created by Davide De Rosa on 24/08/15.
//  Copyright (c) 2015 Davide De Rosa. All rights reserved.
//
//  http://github.com/keeshux
//  http://twitter.com/keeshux
//  http://davidederosa.com
//
//  This file is part of BitcoinSPV.
//
//  BitcoinSPV is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  BitcoinSPV is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with BitcoinSPV.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>

@protocol WSBlockStore;
@protocol WSParameters;
@protocol WSSynchronizableWallet;
@class WSCoreDataManager;

@interface WSBlockChainDownloader : NSObject

@property (nonatomic, assign) double bloomFilterRateMin;                    // 0.0001
@property (nonatomic, assign) double bloomFilterRateDelta;                  // 0.0004
@property (nonatomic, assign) double bloomFilterObservedRateMax;            // 0.005
@property (nonatomic, assign) double bloomFilterLowPassRatio;               // 0.01
@property (nonatomic, assign) NSUInteger bloomFilterTxsPerBlock;            // 600
@property (nonatomic, assign) NSUInteger blockStoreSize;                    // 2500
@property (nonatomic, assign) NSTimeInterval requestTimeout;                // 15.0
@property (nonatomic, strong) WSCoreDataManager *coreDataManager;           // nil

- (instancetype)initWithStore:(id<WSBlockStore>)store headersOnly:(BOOL)headersOnly;
- (instancetype)initWithStore:(id<WSBlockStore>)store fastCatchUpTimestamp:(uint32_t)fastCatchUpTimestamp;
- (instancetype)initWithStore:(id<WSBlockStore>)store wallet:(id<WSSynchronizableWallet>)wallet;
- (id<WSParameters>)parameters;
- (BOOL)shouldDownloadBlocks;
- (BOOL)needsBloomFiltering;

@end
