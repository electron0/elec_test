function updateImages()
	{
		if( bImageSwitch )
		{
			self.showImage(iImgIndex, oImgFrameA, oImgFrameB);
			// setTimeout(self.hideImage, iInterval/2, iImgIndex, oImgFrameB);
		}
		else
		{
			self.showImage(iImgIndex, oImgFrameB, oImgFrameA);
			// setTimeout(self.hideImage, iInterval/2, iImgIndex, oImgFrameA);
		}
		
		bImageSwitch = !bImageSwitch;
		
		// kopieren
		// z = 10
		// fadeIn
		// #and: z = 0
		// #and: hide
		
		// setTimeout(self.hideImage, iInterval*2, iImgIndex);
		
		++iImgIndex;
		if( iImgIndex >= self.arImages.length )
			iImgIndex = 0;
			
		
	};
	
	this.toggleAni = function()
	{
		if( bAni )
		{
			// stop
			
			bAni = false;
		}
		else
		{
			//start
			updateGUI( oImgFrameA, this.arImages[iImgIndex].title, this.arImages[iImgIndex].desc );
			
			// this.showImage(iImgIndex++, oImgFrameA);
			updateImages();
			
			trIntervalTimer = setInterval(updateImages, iInterval);
			bAni = true;
		}
		
		
		
	};